class Solution {
public:
    int reverse(int x) {
        int a;
        char b;
        int result = 0;
        vector<char> v;
        
        if (x < 0){
            a = -x;
        }else{
            a = x;
        }
        
        while(a){
            b = a % 10;
            v.push_back(b + '0');
            a /= 10;
        }
        
        if (v.size() == 10 && v[0] > '2'){
            return 0;
        }
        
        for (int i = 0 ; i < v.size(); i++){
            result *= 10;
            result += v[i] - '0';
            if (result < 0){
                return 0;
            }
        }
        
        if (x < 0){
            return -result;
        }else{
            return result;
        }
    }
};
