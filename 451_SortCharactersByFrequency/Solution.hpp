class Solution {
public:
    string frequencySort(string s) {
        int hash[128] = {0};
        map<int, vector<char> > maps;
        string ret;
        for (auto c : s){
            hash[(int)c] ++;
        }
            
        for (int i = 0; i < 128; i++){
            if (hash[i] == 0)
                continue;
            if (maps.count(hash[i]) == 0){
                vector<char> v(1, char(i));
                maps[hash[i]] = v;
            }else{
                maps[hash[i]].push_back((char)i);
            }
        }
        map<int, vector<char> >::reverse_iterator riter = maps.rbegin();
        for (; riter != maps.rend(); riter++){
            for(auto c : riter->second){
                string t = string(riter->first, c);
                ret += t;
            }
        }
        return ret;
    }
};
