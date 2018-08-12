class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid = (left + right) / 2;
        int begin = -1;
        int end = -1;
        while (left <= right){
            if (nums[mid] < target){
                left = mid + 1;
                mid = (left + right) / 2;
            }else if (nums[mid] > target){
                right = mid - 1;
                mid = (left + right) / 2;
            }else{
                int i = mid;
                for(; i < size; i++){
                    if (nums[i] != target){
                        end = i - 1;
                        break;
                    }
                }
                if (i == size){
                    end = size - 1;
                }
                i = mid;
                for (; i >= 0; i--){
                    if (nums[i] != target){
                        begin = i + 1;
                        break;
                    }
                }
                if (i == -1){
                    begin = 0;
                }
                break;
            }
        }
        res.push_back(begin);
        res.push_back(end);
        return res;
    }
};
