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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        TreeNode * p = root;
        vector<int> v;
        
        if (root == NULL){
            return v;
        }
        
        while(p != NULL){
            v.push_back(p->val);
            if (p->right != NULL){
                stack.push(p->right);
            }
            
            if (p->left != NULL){
                p = p->left;
            }else if (!stack.empty()){
                p = stack.top();
                stack.pop();
            }else{
                p = NULL;
            }
        }
        
        return v;
    }
};
