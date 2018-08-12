class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0)
            return 0;
        s_ = s;
        int ret = 0;
        bool start = false;
        for (int i = 0; i < s_.size(); i++){
            if (!start && isWordBegin(i)){
                start = true;
            }
            if (start && isWordEnd(i)){
                start = false;
                ret += 1;
            }
        }
        return ret;
    }
    
    bool isSpace(char c){
        return c == ' '? true : false;
    }
    
    bool isWordBegin(int i){
        if ((i == 0 && !isSpace(s_[i])) || (isSpace(s_[i-1]) && !isSpace(s_[i])))
            return true;
        return false;
    }
    
    bool isWordEnd(int i){
        if (i == s_.size() - 1 || (!isSpace(s_[i]) && isSpace(s_[i+1])))
            return true;
        return false;
    }
private:
    string s_;
};
