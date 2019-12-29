class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int begin = 0, end = 0, head = 0, dist = INT_MAX;
        int counter = t.size();
        for (auto &c : t) {
            map[c] += 1;
        }
        
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0){
                if (end - begin < dist) {
                    dist = end - (head = begin);
                }
                if (map[s[begin++]]++ == 0) {
                    counter ++;
                }
            }
        }
        
        return dist == INT_MAX ? "" : s.substr(head, dist);
    }
};
