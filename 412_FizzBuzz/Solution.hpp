class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++){
            string s = handle(i);
            ret.push_back(s);
        }
        return ret;
    }
    
    string handle(int i){
        if (i % 15 == 0){
            return "FizzBuzz";
        }else if(i % 5 == 0){
            return "Buzz";
        }else if(i % 3 == 0){
            return "Fizz";
        }else{
            stringstream s;
            s << i;
            return s.str();
        }
    }
};
