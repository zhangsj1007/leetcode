class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        vector<pair<int, int> > sol;
        for (auto p : people){
            sol.insert(sol.begin() + p.second, p);
        }
        return sol;
    }
};
