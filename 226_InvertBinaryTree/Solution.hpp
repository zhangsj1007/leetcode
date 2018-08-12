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
    TreeNode* invertTree(TreeNode* root) {
        invertTreeOneByOne(root);
        return root;
    }
    
    void invertTreeOneByOne(TreeNode* root){
        if (root != NULL && (root->left != NULL || root->right != NULL)){
            TreeNode* tNode = root->left;
            root->left = root->right;
            root->right = tNode;
            if (root->left != NULL)
                invertTreeOneByOne(root->left);
            if (root->right != NULL)
                invertTreeOneByOne(root->right);
        }
    }
    
};
