class Solution {
public:
    int directions[4][2] = {{0,-1}, {-1,0}, {1, 0}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    q.push(make_pair(i, j));
                }else{
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        
        while (!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            for (auto dir : directions){
                int i1 = i + dir[0];
                int j1 = j + dir[1];
                if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n || matrix[i1][j1] <= matrix[i][j] + 1){
                    continue;
                }
                matrix[i1][j1] = matrix[i][j] + 1;
                q.push(make_pair(i1, j1));
            }
        }
        return matrix;
    }
};
