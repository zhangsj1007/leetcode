class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0)
            return 0;
        //consider the condition that the first num is larger than the vector size
        int index = -1;
        sort(citations.begin(), citations.end());
        //find the privot that near the demarcation point
        for(int i = citations.size() - 1; i >= 0; i--){
            if (citations[i] <= citations.size() - i){
                index = i;
                break;
            }
        }
        // 2 conditions
        if (citations[index] != citations.size() - index)
            return citations.size() - index - 1;
        else
            return citations.size() - index;
    }
};
