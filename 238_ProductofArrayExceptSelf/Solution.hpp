class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int t;
        vector<int> v(nums.size());
        int i;
        
        /*  v[0]=1
            v[1]=v[0]
            v[2]=v[0]*v[1]
            v[3]=v[0]*v[1]*v[2]
            ...
            v[n]=v[0]*v[1]*...*v[n-1]
        */
        
        v[0] = 1;
        for(i = 1; i < nums.size(); i++){
            t = nums[i-1];
            v[i] = v[i-1] * t;
        }
        
        t = 1;
        /*  v[0]=v[1]*v[2]*...*v[n]
            ...
            v[n]=v[0]*v[1]*...*v[n-1]
        */
        for(i = nums.size() - 2; i >= 0; i--){
            t *= nums[i+1];
            v[i] *= t; 
        }
        
        return v;
    }
};
