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
    bool isBalanced(TreeNode *root) {
        int depth;
        return _isBalanced(root, &depth);
    }
    
    bool _isBalanced(TreeNode *root, int *depth){
        if (root == NULL){
            *depth = 0;
            return true;
        }
        int left, right;
        if (_isBalanced(root->left, &left) && _isBalanced(root->right, &right)){
            int diff = left - right;
            if (diff >= -1 && diff <= 1){
                *depth = (left > right ? left : right) + 1;
                return true;
            }
        }
        return false;
    }
};
