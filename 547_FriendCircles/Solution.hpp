
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()){
            return 0;
        }
        int groups = 0;
        vector<bool> visited(M.size(), false);
        for (int i = 0; i < M.size(); i++){
            if (!visited[i]){
                groups += dfsFindFriend(i, M, visited) > 0;
            }
        }
        return groups;
    }
private:
    int dfsFindFriend(int i, vector<vector<int>>& m, vector<bool>&visited){
        if (visited[i]){
            return 0;
        }
        visited[i] = true;
        int friends = 1;
        for (int j = 0; j < m.size(); j++){
            if (i != j && m[i][j] == 1){
                friends += dfsFindFriend(j, m, visited);
            }
        }
        return friends;
    }
};
