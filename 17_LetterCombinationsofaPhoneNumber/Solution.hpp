class Solution {
private:
    map<int, string> map_;
    
    void init(){
        map_[2] = "abc";
        map_[3] = "def";
        map_[4] = "ghi";
        map_[5] = "jkl";
        map_[6] = "mno";
        map_[7] = "pqrs";
        map_[8] = "tuv";
        map_[9] = "wxyz";
    } 
    
    void helper(vector<string>& v, int n, string& path, vector<string>& ans){
        if (n == v.size()){
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < v[n].size(); i++){
            path.push_back(v[n][i]);
            helper(v, n+1, path, ans);
            path.erase(path.length() - 1, 1);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        init();
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        int size = digits.size();
        vector<string> v;
        string path;
        
        for(int i = 0; i < size; i++){
            v.push_back(map_[(int)(digits[i] - 48)]);
        }
        
        helper(v, 0, path, ans);
        return ans;
    }
};
