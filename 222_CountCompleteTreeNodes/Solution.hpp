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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        TreeNode* left = root;
        TreeNode* right = root;
        int leftHeight = 0;
        int rightHeight = 0;
        while(left){
            leftHeight++;
            left = left->left;
        }
        while(right){
            rightHeight++;
            right = right->right;
        }
        
        if (leftHeight == rightHeight){
            return pow(2, leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
