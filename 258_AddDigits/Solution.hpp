class Solution {
public:
    int addDigits(int num) {
        vector<int> v;
        while(num / 10){
            v.push_back(num % 10);
            num /= 10;
        }
        v.push_back(num);
        num = accumulate(v.begin(), v.end(), 0);
        if(num < 10)
            return num;
        else
            return addDigits(num);
    }
};
