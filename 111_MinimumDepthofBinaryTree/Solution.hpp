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
    int minDepth(TreeNode *root) {
        if (root == NULL){
            return 0;}
        int depth = 0;
        _MinDepth(root, &depth);
        return minDep;
    }
    Solution(){minDep = -1;}
    
    void _MinDepth(TreeNode *root, int * depth){
        (*depth)++;
        if (root->left == NULL && root->right == NULL){
            if (minDep == -1){
                minDep = *depth;
                (*depth)--;
                return;
            }
            
            if (*depth < minDep){
                minDep = *depth;
                (*depth)--;
                return;
            }
        }
        
        if (*depth > minDep && minDep > -1){
            (*depth)--;
            return;
        }
        
        if (root->left != NULL){
            _MinDepth(root->left, depth);
        }
        
        if (root->right !=NULL){
            _MinDepth(root->right, depth);
        }
        (*depth)--;
    }
private:
   int minDep;
};
