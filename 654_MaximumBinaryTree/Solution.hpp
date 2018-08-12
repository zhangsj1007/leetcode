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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() > 0){
            return constructMaximumBinaryTreeCore(nums, 0, nums.size() - 1);
        }else{
            return nullptr;
        }
    }
        
    TreeNode* constructMaximumBinaryTreeCore(vector<int>& nums, int start, int end){
        if (start == end){
            TreeNode *treeNode = new TreeNode(nums[start]);
            return treeNode; 
        }
        
        int maxElem = INT_MIN;
        int maxIdx = -1;
        for (int i = start; i <= end; i++){
            if (nums[i] > maxElem){
                maxElem = nums[i];
                maxIdx = i;
            }
        }
        
        TreeNode *treeNode = new TreeNode(maxElem);
        if (maxIdx > start){
            treeNode->left = constructMaximumBinaryTreeCore(nums, start, maxIdx - 1);
        }
        
        if (maxIdx < end){
            treeNode->right = constructMaximumBinaryTreeCore(nums, maxIdx + 1, end);
        }
        
        return treeNode;
    }
    
};
