class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        for (int i = 0; i < numCourses; i++){
            if (!visited[i] && dfsCircle(graph, i, visited, onpath)){
                return false;
            }
        }
        return true;
    }
private:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites){
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    bool dfsCircle(vector<unordered_set<int>>& graph, int node, vector<bool>& visited, vector<bool>& onpath){
        //说明这个点之前访问过，如果这个点造成了环，那么之前就已经运行计算过了
        if (visited[node])
            return false;
        visited[node] = onpath[node] = true;
        for (auto neigh : graph[node]){
            if (onpath[neigh] || dfsCircle(graph, neigh, visited, onpath)){
                return true;
            }
        }
        return onpath[node] = false;
    }
};
