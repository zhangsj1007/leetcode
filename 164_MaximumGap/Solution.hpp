class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int maxValue = *max_element(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());
        if (maxValue == minValue){
            return 0;
        }
        int gapInterval = ceil((double)(maxValue - minValue) / (nums.size() - 1));
        int bucketNum = ceil((double)(maxValue - minValue) / gapInterval);
        
        vector<pair<int, int> > buckets(bucketNum, make_pair(INT_MIN, INT_MAX));
        for (auto num : nums){
            if (num == minValue || num == maxValue) continue;
            int i = (num - minValue) / gapInterval;
            if (num > buckets[i].first) buckets[i].first = num;
            if (num < buckets[i].second) buckets[i].second = num;
        }
        
        int maxGap = 0, lastValue = minValue;
        for (auto bucket : buckets){
            if (bucket.first == INT_MIN) continue;
            maxGap = max(maxGap, bucket.second - lastValue);
            lastValue = bucket.first;
        }
        maxGap = max(maxGap, maxValue - lastValue);
        return maxGap;
    }
};
