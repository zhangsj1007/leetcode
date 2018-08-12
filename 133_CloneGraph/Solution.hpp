/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node){
            return NULL;
        }
        if (mp.find(node) == mp.end()){
            mp[node] = new UndirectedGraphNode(node->label);
            for (auto neigh : node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(neigh));
            }
        }
        return mp[node];
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
};
