/*
    算法：自己刚刚把事情想得复杂，而且不好解决。其实这个问题就是包含第一个不包含最后一个的序列，和包含最后一个不包含第一个的序列的两种求法，哪一个最大。简化问题，抽象问题是能力！
*/

class Solution {
public:
    struct Node{
        bool include1;
        int value;
        Node(bool _include1 = 0, int _value = 0) : include1(_include1), value(_value){}
    };
    
    int rob(vector<int>& nums) {
        /*if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
       vector<Node> v;
       Node p;
       int size;
       v.push_back(p);
       v.push_back(p);
       p.include1 = 1;
       p.value = nums[0];
       v.push_back(p);
       for (int i = 1; i < nums.size(); i++) {
           Node t;
           if (v[i+1].value > v[i].value + nums[i]){
               t = v[i+1];
           }else{
               t.value = v[i].value + nums[i];
               t.include1 = v[i].include1;
           }
           v.push_back(t);
       }
       size = v.size();
       if (v[size-1].include1)
           return v[size-2].value;
       else
           return v[size-1].value;*/
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        return max(rob_line(nums, 0, nums.size() - 1), rob_line(nums, 1, nums.size()));
    }
    
    int rob_line(vector<int>& nums, int start, int end){
        int odd_sum = 0;
        int even_sum = 0;
        for (int i = start; i < end; i++){
            if (i % 2)
                odd_sum = max(even_sum, odd_sum + nums[i]);
            else
                even_sum = max(odd_sum, even_sum + nums[i]);
        }
        return odd_sum > even_sum ? odd_sum : even_sum;
    }
};
