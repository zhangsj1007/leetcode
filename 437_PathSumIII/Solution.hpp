/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //date: 2017-7-1
 //desc: 就是用一个map来存储每一个节点和父节点的和的值。
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        map<TreeNode*, vector<int> > sumMap;
        int count = 0;
        stack<TreeNode*> nodeStack;
        stack<TreeNode*> prntNodeStack;
        TreeNode * p = NULL;
        TreeNode * parent = NULL;
        p = root;
        vector<int> v;
        v.push_back(p->val);
        sumMap.insert(make_pair(root, v));
        while(p != NULL){
            if(p == root){
                if (p->val == sum)
                    count++;
            }else{
                vector<int>& vParent = sumMap[parent];
                vector<int> vNode;
                for (int i = 0; i < vParent.size(); i++){
                    if (p->val + vParent[i] == sum)
                        count++;
                    vNode.push_back(p->val + vParent[i]);
                }
                if (p->val == sum)
                    count++;
                vNode.push_back(p->val);
                sumMap[p] = vNode;
            }
            
            if (p->right != NULL){
                nodeStack.push(p->right);
                prntNodeStack.push(p);
            }
            if (p->left != NULL){
                parent = p;
                p = p->left;
            }else if (!nodeStack.empty()){
                parent = prntNodeStack.top();
                prntNodeStack.pop();
                p = nodeStack.top();
                nodeStack.pop();
            }else{
                p = NULL;
                parent = NULL;
            }
        }
        return count;
    }
};
