class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        for(auto price : prices){
            buy = max(buy, - price);
            sell = max(sell, buy+price);
        }
        return sell;
    }
};
