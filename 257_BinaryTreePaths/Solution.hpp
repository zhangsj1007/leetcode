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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;
        help(ans, root, "");
        return ans;
    }
    
    void help(vector<string> &ans, TreeNode * root, string pre){
        if (root->left == NULL && root->right == NULL){
            ans.push_back(pre + to_string(root->val));
            return;
        }
        if (root->left != NULL)
            help(ans, root->left, pre + to_string(root->val) + "->");
        if(root->right != NULL)
            help(ans, root->right, pre + to_string(root->val) + "->");
    }
};
