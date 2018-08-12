class Solution {
public:
    //1.需要检查dfs是否有环
    //2.onpath的使用
    //3.reverse的使用
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        //stack<int> toposort;
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        vector<int> toposort;
        for (int i = 0; i < numCourses; i++){
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort)){
               return {};
            }
        }
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites){
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort){
        if (visited[node]){
            return false;
        }
        onpath[node] = visited[node] = true;
        for (auto link : graph[node]){
            if (onpath[link] || dfs(graph, link, onpath, visited, toposort)){
                return true;
            }
        }
        toposort.push_back(node);
        return onpath[node] = false;
    }
};
