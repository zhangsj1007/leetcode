class Solution {
public:
    enum Symbol{
        negative = 0,
        positive = 1
    };
    
    int calculate(string s) {
        symbolVec_.push_back(positive);
        operatorVec_.push_back('+');
        string num;
        
        for (int i = 0; i < s.size(); i++){
            if (isNum(s[i])){
                num.push_back(s[i]);
                if (i + 1 == s.size() || !isNum(s[i+1])){
                    numVec_.push_back(atoi(num.c_str()));
                    num.clear();
                }
            }else if (s[i] == ' '){
                continue;
            }else if(isOperator(s[i])){
                char symbol = symbolVec_.back();
                if (symbol == negative){
                    if (s[i] == '+')
                        operatorVec_.push_back('-');
                    if (s[i] == '-')
                        operatorVec_.push_back('+');
                }else{
                    operatorVec_.push_back(s[i]);
                }
            }else if(s[i] == '('){
                char oper = operatorVec_.back();
                if (oper == '+'){
                    symbolVec_.push_back(positive);
                }else{
                    symbolVec_.push_back(negative);
                }
            }else if (s[i] == ')'){
                symbolVec_.pop_back();
            }
        }
        
        int result = numVec_[0];
        for (int i = 1; i < operatorVec_.size(); i++){
            if (operatorVec_[i] == '+'){
                result += numVec_[i];
            }else{
                result -= numVec_[i];
            }
        }
        return result;
    }
    
    bool isNum(char c){
        if (c >= '0' && c <= '9')
            return true;
        else
            return false;
    }
    
    bool isOperator(char c){
        if (c == '+' || c == '-')
            return true;
        else
            return false;
    }
    
private:
    vector<Symbol> symbolVec_;
    vector<char> operatorVec_;
    vector<int> numVec_;
};
