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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;
        int curSum = 0;
        return _HasPathSum(root, sum, &curSum);
    }
    bool _HasPathSum(TreeNode *root, int sum, int* curSum){
        bool found = false;
        bool found2 = false;
        *curSum += root->val;
        if (*curSum == sum && root->left == NULL && root->right == NULL){
            found = true;
            return found;
        }
        if(root->left != NULL){
            found = _HasPathSum(root->left, sum, curSum);
        }
        if (root->right != NULL){
            found2 = _HasPathSum(root->right, sum, curSum);
        }
        *curSum -= root->val;
        return found |found2;
    }
};
