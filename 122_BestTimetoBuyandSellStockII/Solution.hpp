class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0){
            return 0;
        }
        
        vector<int> dif;
        int i;
        int sum = 0;
        
        for(i = 1; i < prices.size(); i++){
            dif.push_back(prices[i] - prices[i-1]);
        }
        
        //每两手两手买，只要赚钱就买
        for (i = 0; i < dif.size(); i++){
            if (dif[i] > 0){
                sum += dif[i];
            }
        }
        
        return sum;
    }
};
