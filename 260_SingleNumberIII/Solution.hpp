class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        bitset<32> bs;
        int n1 = 0;
        int n2 = 0;
        vector<int> v;
        bs.reset();
        int i, j;
        for (i = 0; i < nums.size(); i++)
            bs ^= nums[i];
        for (i = 0; i < 32; i++)
            if(bs.test(i))
                break;
        for(j = 0; j < nums.size(); j++){
            if(bitset<32>(nums[j]).test(i))
                n1 ^= nums[j];
            else
                n2 ^= nums[j];
        }
        v.push_back(n1);
        v.push_back(n2);
        return v;
    }
};
