class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        if (deck.size() == 0)
            return false;
        
        unordered_map<int, int> cardIdCntMp;
        for (auto id : deck){
            if (cardIdCntMp.count(id) == 0)
                cardIdCntMp[id] = 1;
            else
                cardIdCntMp[id] += 1;
        }
        
        //获得最小元素的个数
        int min = min_element(cardIdCntMp.begin(), cardIdCntMp.end(), [](pair<int, int> p1, pair<int, int> p2){return p1.second < p2.second;})->second;
        
        //如果元素的个数只有一个，不能够partition
        if (min < 2)
            return false;
        
        for (auto iter = cardIdCntMp.begin(); iter != cardIdCntMp.end(); iter++){
            //如果除以最小的元素个数除不尽，不能够partition
            if (gcd(iter->second, min) == 1)
                return false;
        }
        
        return true;
    }
    
private:
    int gcd(int a, int b){
        if (a == 0 && b == 0)
            return 0;
        if (a == 0)
            std::swap(a, b);
    
        while (b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
    
        return a;
    } 
};
