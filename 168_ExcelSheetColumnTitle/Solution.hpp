class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n){
            char temp;
            int i;
            i = n % 26;
            temp = i + 64;
            if (i == 0){
                if (n == 26){
                    s.insert(s.begin(), 'Z');
                    return s;
                }else{
                    s.insert(s.begin(), 'Z');
                    n = n / 26 - 1;
                    continue;
                }
            }else{
                s.insert(s.begin(), temp);
            }
            n /= 26;
        }
        return s;
    }
};
