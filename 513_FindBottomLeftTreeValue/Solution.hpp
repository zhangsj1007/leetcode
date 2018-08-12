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
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL)
            return -1;
        int height = 0;
        return findBottomLeftCore(root, height);
    }
    int findBottomLeftCore(TreeNode* root, int& height){
        if (root->left == NULL && root->right == NULL){
            height = 1;
            return root->val;
        }
        int leftValue = 0, leftHeight = -1;
        int rightValue = 0, rightHeight = -1;
        if (root->left != NULL){
            leftValue = findBottomLeftCore(root->left, leftHeight);
        }
        if (root->right != NULL){
            rightValue = findBottomLeftCore(root->right, rightHeight);
        }
        if (leftHeight == -1){
            height = rightHeight + 1;
            return rightValue;
        }else if (rightHeight == -1){
            height = leftHeight + 1;
            return leftValue;
        }else{
            if (rightHeight > leftHeight){
                height = rightHeight + 1;
                return rightValue;
            }else{
                height = leftHeight + 1;
                return leftValue;
            }
        }
    }
};
