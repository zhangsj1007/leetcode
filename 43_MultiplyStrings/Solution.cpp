class Solution {
public:
    string multiply(string num1, string num2) 
    {
        
        /*if (num1 == "0" || num2 == "0")
            return "0";
        
        int cnt = -1;
        
        int carry = 0;
        
        string res;
        
        vector<string> tempResLst;
        
        for (int i = num1.size() - 1; i >= 0; i--){
            carry = 0;
            cnt++;
            int dig1 = (int)(num1[i] - '0');
            string tempRes;
            
            if (dig1 == 0)
                continue;
            
            for (int j = num2.size() - 1; j >= 0; j--){
                int dig2 = (int)(num2[j] - '0');
                dig2 = dig1 * dig2 + carry;
                carry = dig2 / 10;
                tempRes.push_back(dig2 % 10 + '0');
            }
            
            if (carry > 0)
                tempRes.push_back(carry + '0');
            
            reverse(tempRes.begin(), tempRes.end());
            
            string zeros(cnt, '0');
            
            copy(zeros.begin(), zeros.end(), back_inserter(tempRes));
            
            tempResLst.push_back(tempRes);
        }
        
        res = accumulate(tempResLst.begin(), tempResLst.end(), string("0"), add);
        
        return res;*/

        string sum(num1.size() + num2.size(), '0');
    
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
    
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";

    }
    
    /*static string add (string num1, string num2)
    {
        string res;
        int carry = 0;
        
        res.reserve(max(num1.size(), num2.size()));
        int size = min(num1.size(), num2.size());
        
        for (int i = 0; i < size; i++){
            int dig1 = (int)(num1[num1.size()-1-i] - '0');
            int dig2 = (int)(num2[num2.size()-1-i] - '0');
            
            dig1 = dig1 + dig2 + carry;
            carry = dig1 / 10;
            res.push_back(dig1 % 10 + '0');
        }
        
        const string &temp = num1.size() > size ? num1 : num2;
        
        if (temp.size() > size){
            for (int i = size; i < temp.size(); i++) {
                int dig = (int)(temp[temp.size()-1-i] - '0');
                dig = dig + carry;
                carry = dig / 10;
                res.push_back(dig % 10 + '0');
            }
        }
        
        if (carry > 0)
            res.push_back(carry + '0');
        
        reverse(res.begin(), res.end());
        
        return res;
    }*/
    
};
