/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        stack <TreeNode*> s;
        TreeNode* cur = NULL;
        TreeNode* pre = NULL;
        vector<int> ret;
        map<int, int> m;
        if (root == NULL){
            return ret;
        }
        s.push(root);
        while(!s.empty()){
            cur = s.top();
            bool isLeave = cur->left == NULL && cur->right == NULL;
            if (isLeave || (pre != NULL && (pre == cur->left || pre == cur->right))){
                s.pop();
                if (!isLeave){
                    if (cur->left != NULL){
                        cur->val += cur->left->val;
                    }
                    if (cur->right != NULL){
                        cur->val += cur->right->val;
                    }
                }
                
                if (m.count(cur->val) == 0){
                    m[cur->val] = 1;
                }else{
                    m[cur->val] += 1;
                }
                pre = cur;
            }else{
                if (cur->right != NULL){
                    s.push(cur->right);
                }
                if (cur->left != NULL) {
                    s.push(cur->left);
                }
            }
        }
        
        int count = 0;
        for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++){
            if (iter->second > count){
                count = iter->second;
                ret.clear();
                ret.push_back(iter->first);
            }else if(iter->second == count){
                ret.push_back(iter->first);
            }
        }
        return ret;
    }
};
