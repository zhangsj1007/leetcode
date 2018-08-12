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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        nums_ = nums;
        return buildCore(0, nums.size() - 1);
    }
    
    TreeNode* buildCore(int start, int end){
        if (start == end){
            TreeNode * p = new TreeNode(nums_[start]);
            return p;
        }
        int mid = (start + end) / 2;
        TreeNode *p = new TreeNode(nums_[mid]);
        if (start <= mid-1){
            p->left = buildCore(start, mid-1);
        }
        if (mid+1 <= end){
            p->right = buildCore(mid+1, end);
        }
        return p;
    }
private:
    vector<int> nums_;
};
