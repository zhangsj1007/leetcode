class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        words.insert(make_pair(word.length(), word));
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range;
        range = words.equal_range(word.length());
        for(multimap<int, string>::iterator iter= range.first; iter != range.second; iter++){
            if (isMatch(iter->second, word)){
                return true;
            }
        }
        return false;
    }
private:
    bool isMatch(string s1, string s2){
        for (int i = 0; i < s1.length(); i++){
            if (!(s2[i] == '.' || s1[i] == s2[i])){
                return false;
            }
        }
        return true;
    }
private:
    multimap<int, string> words;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
