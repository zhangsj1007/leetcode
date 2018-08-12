class Solution {
public:
   /* bool wordBreak(string s, unordered_set<string> &dict) {
        bool found1 = false;
        bool found2 = false;
        if (dict.empty())
            return found1;
        unordered_set<string>::iterator iter;
        string::size_type pos = 0;
        string::size_type pos2 = 0;
        while(pos != s.length()){
            pos2 = pos;
            for(iter = dict.begin(); iter != dict.end() && pos != s.length() ; iter++){
                //if(s.find(*iter, pos) != string::npos){
                string temp = *iter;
                if (s.compare(pos, temp.length(), temp) == 0){
                    
                     pos = temp.length() + pos;
                   // break;
                }
            }
            
            //if(iter == dict.end()){
             //   return found;
            //}
            if (pos == pos2)
                break;
        }
        
        
        
        if (pos == s.length()){
            found1 = true;
        }
        
        
        pos = 0;
        while(pos != s.length()){
            //pos2 = pos;
            for(iter = dict.begin(); iter != dict.end() ; iter++){
                //if(s.find(*iter, pos) != string::npos){
                string temp = *iter;
                if (s.compare(pos, temp.length(), temp) == 0){
                    pos = temp.length() + pos;
                    break;
                }
            }
            
            if(iter == dict.end()){
                break;
            }
            //if (pos == pos2)
             //   return found;
        }
        if (pos == s.length())
            found2 = true;
        return (found1 || found2);
    }*/
    
    
    
    
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length() > 50){
            return false;
        }
        return _WordBreak(0, s, dict);
    }
    
    bool _WordBreak(int k, string s, unordered_set<string> &dict){
        bool result = false;
        string t;
        for(int i = k; i < s.length(); i++){
            t.assign(s, k, i-k+1);
            if (WordCompare(t, dict)){
                if (i == s.length() - 1){
                    result = true;
                    break;
                }
                result = _WordBreak(i + 1, s, dict);
                if (result){
                    break;
                }
            }
        }
        return result;
    }
    
    bool WordCompare(string s, unordered_set<string> &dict){
        unordered_set<string>::iterator iter;
        for (iter = dict.begin(); iter != dict.end(); iter++){
            if (s.compare(*iter) == 0){
                return true;
            }
        }
        return false;
    }
};
