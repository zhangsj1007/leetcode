class Solution {
public:
    bool wordPattern(string pattern, string str) {
        multimap<char, string> mMap;
        vector<string> v;
        istringstream in(str);
        string t;
        while(in >> t)
            v.push_back(t);
        if (pattern.size() != v.size())
            return false;
        for(int i = 0; i < pattern.size(); i++){
            mMap.insert(make_pair(pattern[i], v[i]));
        }
        multimap<char, string>::iterator it = mMap.begin();
        while(it != mMap.end()){
            pair<multimap<char,string>::iterator, multimap<char, string>::iterator> p = mMap.equal_range(it->first);
            it = p.first;
            string t = p.first->second;
            //检查相同的key，value相同
            while(it != p.second){
                if(t != it->second)
                    return false;
                it++;
            }
            //检查不同的key，value不同
            if (it != mMap.end()){
                if(p.first->second == p.second->second)
                    return false;
            }
        }
        return true;    
    }
};
