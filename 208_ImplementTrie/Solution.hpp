class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char value = 'a') : value_(value),isWordEnd_(false)
    {
    }
    const vector<TrieNode*>& getChildren(){
        return children_;
    }
    void insertChild(TrieNode* child){
        children_.push_back(child);
    }
    char getValue(){
        return value_;
    }
    void setVaule(char value){
        value_ = value;
    }
    bool getIsWordEnd(){
        return isWordEnd_;
    }
    void setWordEnd(){
        isWordEnd_ = true; 
    }
    void cancelWordEnd(){
        isWordEnd_ = false;
    }
private:
    char value_;
    bool isWordEnd_;
    vector<TrieNode*> children_;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * tNode = root;
        for (auto val : word){
            bool find = false;
            const vector<TrieNode*> children = tNode->getChildren();
            for (auto child : children){
                if (child->getValue() == val){
                    find = true;
                    tNode = child;
                    break;
                }
            }
            if (!find){
                TrieNode * childNode = new TrieNode(val);
                tNode->insertChild(childNode);
                tNode = childNode;
            }
        }
        tNode->setWordEnd();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * tNode = root;
        for (auto val : word){
            bool find = false;
            const vector<TrieNode*> children = tNode->getChildren();
            for (auto child : children){
                if (child->getValue() == val){
                    find = true;
                    tNode = child;
                    break;
                }
            }
            if (!find){
                return false;
            }
        }
        if (tNode->getIsWordEnd())
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * tNode = root;
        for (auto val : prefix){
            bool find = false;
            const vector<TrieNode*> children = tNode->getChildren();
            for (auto child : children){
                if (child->getValue() == val){
                    find = true;
                    tNode = child;
                    break;
                }
            }
            if (!find){
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
