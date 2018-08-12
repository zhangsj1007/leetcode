/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> v;
        TreeNode * p = root;
        bool flag = true;
        
        if (root == NULL){
            return v;
        }
        
        while(flag){
            while(p != NULL){
                stack.push(p);
                p = p->left;
            }
            
            if (stack.empty()){
                flag = false;
            }else{
                p = stack.top();
                stack.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }
        
        return v;
    }
};
