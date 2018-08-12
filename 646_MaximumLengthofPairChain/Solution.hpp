class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int count = 0;
        sort(pairs.begin(), pairs.end(), compare);
        for (int i = 0, j = 0; j < pairs.size(); j++){
            if (j == 0 || pairs[i][1] < pairs[j][0]){
                count++;
                i = j;
            }
        }
        return count;
    }
private:
    static bool compare(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }
};
