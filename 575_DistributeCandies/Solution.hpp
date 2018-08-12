class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        //这应该才是这道题的考点，利用bit做hash，比利用set快好多
        //hash的访问范围是0，1，。。。，200000， 所以要有200001位
        bitset<200001> hash;
        //int count = 0;
        for (int i : candies) {
            if (!hash.test(i+100000)) {
               hash.set(i+100000);
            }
        }
        return min(hash.count(), candies.size()/2);
    }
};
