class Solution {
public:
    string decodeString(string s) {
        if (s == "")
            return s;
        int num = 0;
        string t;
        bool isFrontBracketBegin = false;
        for (char c : s){
            if (isBracketBegin(c)){
                countList_.push_back(num);
                isFrontBracketBegin = true;
                num = 0;
            }else if (isBracketEnd(c)){
                if (t != ""){
                    if (isFrontBracketBegin){
                        stringList_.push_back(t);
                    }else{
                        t = stringList_.back() + t;
                        stringList_.pop_back();
                        stringList_.push_back(t);
                    }
                    t.clear();
                }
                merge();
                isFrontBracketBegin = false;
            }else if (isChar(c)){
                t.push_back(c);
            }else{
                if(t != ""){
                    stringList_.push_back(t);
                    if (countList_.size() < stringList_.size()){
                        countList_.push_back(1);
                        merge();
                    }
                    t.clear();
                }
                num *= 10;
                num += (int)(c - '0');
            }
        }
        if (stringList_.empty())
            return t;
        else 
            return stringList_.back() + t;
    }
private:
    bool isBracketBegin(char c){
        return c == '[' ? true : false;
    }
    bool isBracketEnd(char c){
        return c == ']' ? true : false;
    }
    bool isChar(char c){
        return c >= 'a' && c <= 'z' ? true : false;
    }
    bool isDigit(char c){
        return c >= '0' && c <= '9' ? true : false;
    }
    //遇到数字和“]”, 向前归并
    void merge(){
        string t = stringList_.back();
        int count = countList_.back();
        stringList_.pop_back();
        countList_.pop_back();
        string newString;
        for (int i = 0; i < count; i++)
            newString += t;
        if(stringList_.empty()){
            if (countList_.empty()){
                countList_.push_back(1);
            }
            stringList_.push_back(newString);
        }else{
            newString = stringList_.back() + newString;
            stringList_.pop_back();
            stringList_.push_back(newString);
        }
    }
    list<int> countList_;
    list<string> stringList_;
};
