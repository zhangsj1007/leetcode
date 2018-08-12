class Solution {
public:
    class Key{
    public:
        Key(){
            for (int i = 0; i < 26; i++){
                a[i] = 0;
            }
        }
        Key(unsigned int* aa){
            for (int i = 0; i < 26; i++){
                a[i] = aa[i];
            }
        }
        bool operator < (const Key& key) const{
            for (int i = 0; i < 26; i++){
                if (a[i] < key[i])
                    return true;
                else if (a[i] > key[i])
                    return false;
            }
            return false;
        }
        const unsigned int& operator[](unsigned int i) const{
            return a[i];
        }
    private:
        unsigned int a[26];
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        if (strs.size() == 0)
            return res;
        multimap<Key, string> mm;
        for (int i = 0; i < strs.size(); i++){
            unsigned int a[26] = {0};
            for (int j = 0; j < strs[i].size(); j++){
                a[(int)(strs[i][j]-'a')]++;
            }
            mm.insert(make_pair(a, strs[i]));
        }
        for (multimap<Key, string>::iterator iter = mm.begin(); iter != mm.end(); iter = mm.upper_bound(iter->first)){
            pair<multimap<Key, string>::iterator, multimap<Key, string>::iterator> p = mm.equal_range(iter->first);
            vector<string> v;
            for (multimap<Key, string>::iterator it = p.first; it != p.second; it++){
                v.push_back(it->second);
            }
            res.push_back(v);
        }
        return res;
    }
};
