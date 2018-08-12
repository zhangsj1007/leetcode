class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int i, j, k;
        string s1, s2, s3, s4, sIP;
        vector <string> v;
        
        if (s.length() < 4 || s.length() > 12){
            return v;
        }
        
        for(i = 1; (i < 4) && (s.length() - i >= 3); i++){
            if (s.length() - i > 9){
                continue;
            }
            s1.assign(s, 0, i);       // s1 = s[0,i];
            for(j =  1; (j < 4) && (s.length() - i - j >= 2); j++){
                if (s.length() -i - j > 6){
                    continue;
                }
                s2.assign(s, i, j);   // s2 = s[i,i+j];
                for(k = 1; (k < 4) && (s.length() - i - j - k >= 1); k++){
                    if (s.length() - i - j - k > 3){
                        continue;
                    }
                    s3.assign(s, i+j, k);
                    s4.assign(s, i+j+k, s.length()-i-j-k);
                    if (ISValidIPPart(s1) && ISValidIPPart(s2) && ISValidIPPart(s3) && ISValidIPPart(s4)){
                        sIP += s1;
                        sIP += '.';
                        sIP += s2;
                        sIP += '.';
                        sIP += s3;
                        sIP += '.';
                        sIP += s4;
                        v.push_back(sIP);
                        sIP.clear();
                    }
                }
            }
        }
        return v;
    }
    
    bool ISValidIPPart(string s){
        if (s.length() == 0){
            return false;
        }
        
        if (s.length() > 1 && s[0] == '0'){
            return false;
        }
        
        int num = 0;
        for (int i = 0 ; i < s.length(); i++){
            num *= 10;
            num += s[i] - '0';
        }
        if (num >= 0 && num <= 255){
            return true;
        }else{
            return false;
        }
    }
    
};
