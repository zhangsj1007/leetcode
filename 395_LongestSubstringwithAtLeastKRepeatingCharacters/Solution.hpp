class Solution {
public:
    int longestSubstring(string s, int k) {
        int count[26] = {0};
        string str;
        vector<int> places;
        size_t found = 0;
        int maxLength = 0;
        bool flag = true;
        
        for(int i = 0; i < s.length(); i++){
            count[(int)(s[i]-'a')]++;
        }
        for(int i = 0; i < 26; i++){
            if (count[i] > 0 && count[i] < k)
                str.push_back((char)(i + 97));
        }
        places.push_back(0);
        found = s.find_first_of(str);
        while(found != std::string::npos){
            places.push_back(found);
            found = s.find_first_of(str, found + 1);
        }
        places.push_back(s.length());
        for(int i = 0; i < places.size() - 1; i++){
            flag = true;
            if (places[i+1] - places[i] > 1 && places[i+1] - places[i] > maxLength){
                string substr;
                if(i == 0){
                    substr = s.substr(places[i], places[i+1] - places[i]);
                }else{
                    substr = s.substr(places[i]+1, places[i+1] - places[i]);
                }
                map<char, int> charCount;
                for (int i = 0; i < substr.length(); i++){
                    charCount[substr[i]] += 1;
                }
                
                map<char,int>::iterator iter = charCount.begin();
                for(; iter != charCount.end(); iter++){
                    if(iter->second < k)
                        flag = false;
                }
                
                if (flag){
                    if (i == places.size() - 2 && i != 0) maxLength = places[i+1] - places[i] - 1;
                    else maxLength = places[i+1] - places[i];
                } 
                else maxLength = longestSubstring(substr, k);
            }
        }
        return maxLength;
    }
};
