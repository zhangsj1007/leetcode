class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN;
        int firstSell = 0;
        int secondBuy = INT_MIN;
        int secondSell = 0;
        
        for (auto price : prices){
            if (firstBuy < -price) firstBuy = -price;
            if (firstSell < firstBuy + price) firstSell = firstBuy + price;
            if (secondBuy < firstSell - price) secondBuy = firstSell - price;
            if (secondSell < secondBuy + price) secondSell = secondBuy + price;
        }
        return secondSell;
    }
};
