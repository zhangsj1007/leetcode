class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        int low = 0, high = length - 1;
        while (low < high){
            int mid = (low + high) / 2;
            int midRight = mid + 1;
            if (nums[mid] > nums[midRight]){
                high = mid;
            }else{
                low = midRight;
            }
        }
        return low;
    }
};
