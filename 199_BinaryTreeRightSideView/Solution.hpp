/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct _TreeNode{
    TreeNode *p;
    int flag;
   // _TreeNode(TreeNode *root = NULL): p(root), flag(0) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        /*queue<_TreeNode> queueT;
        vector<int> v;
        if (root == NULL)
            return v;
        _TreeNode r, temp;
        r.p = root;
        r.flag = 1;
        queueT.push(r);
        while(!queueT.empty()){
            r = queueT.front();
            queueT.pop();
            if (r.flag)
                v.push_back(r.p->val);
                
            if (r.p->left != NULL){
                temp.p = r.p->left;
                temp.flag = 0;
                if (r.p->right == NULL)
                    temp.flag = 1;
                queueT.push(temp);
            }
            
            if (r.p->right != NULL){
                temp.p = r.p->right;
                if (r.flag == 1)
                    temp.flag = 1;
                else
                    temp.flag = 0;
                queueT.push(temp);
            }
        }
        return v;*/
        //这道题还是很有技巧的，自己没有想出来。
        vector<int> v;
        queue<TreeNode*> q;
        if (root == NULL)
            return v;
        q.push(root);
        while(q.size()){
            int k;
            k = q.size();
            //一个循环完全把上一批处理干净。
            for(int i = 0; i < k; i++){
                TreeNode *rt = q.front();
                if (i == 0) v.push_back(rt->val);
                //right,right,一直right，最右边的下一轮就变成了第一个。
                if (rt->right) q.push(rt->right);
                if (rt->left) q.push(rt->left);
                q.pop();
            }
        }
        return v;
    }
};
