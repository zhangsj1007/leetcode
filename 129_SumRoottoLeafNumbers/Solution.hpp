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
    Solution(){sum = 0;}
    
    int sumNumbers(TreeNode *root) {
        if (root == NULL){
            return 0;
        }
         vector<int> stack;
         _sumNumbers(root, stack);
         return sum;
    }
    
    void _sumNumbers(TreeNode * root, vector<int> & stack){
        int i;
        int sum2 = 0;
        stack.push_back(root->val);
        if (root->left == NULL && root->right == NULL){
            for (i = 0; i < stack.size(); i++){
                sum2 *= 10;
                sum2 += stack[i];
            }
            sum += sum2;
        }
        if (root->left != NULL){
            _sumNumbers(root->left, stack);
        }
        if (root->right != NULL){
            _sumNumbers(root->right, stack);
        }
        stack.pop_back();
    }
private:
    int sum;
};
