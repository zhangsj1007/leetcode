class Solution {
public:
    //hash解决问题看能不能追溯回去，追溯回去形成环就肯定不是happy number了
    bool isHappy(int n) {
        unordered_map<int, bool> m;
        int t;
        t = 0;
        int i;
        m[n] = 1;
        
        while(1){
            while(n){
                i = n % 10;
                t += i * i;
                n /= 10;
            }
            if(t == 1) return true;
            if(m[t]++) return false;
            n = t;
            t = 0;
        }
    }
};
