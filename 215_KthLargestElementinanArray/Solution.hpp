class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n;
        int start, end;
        start = 0;
        end = nums.size() - 1;
        n = index(nums, start, end);
        while(n != k - 1){
            if (n < k - 1){
                start = n + 1;
                n = index(nums, start, end);
            }else{
                end = n - 1;
                n = index(nums, start, end);
            }
        }
        return nums[n];
    }
    
    void swap(int* a, int *b){
        int t;
        t = *a;
        *a = *b;
        *b = t;
    }
    
    int index(vector<int>& nums, int start, int end){
        int big = start - 1;
        for (int i = start; i < end; i++){
            if (nums[i] > nums[end]){
                big++;
                if(i != big)
                    swap(&nums[big], &nums[i]);
            }
        }
        big++;
        swap(&nums[end], &nums[big]);
        return big;
    }
};
