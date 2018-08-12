class Solution {
public:
    
    struct Node{
        unordered_set<int> neighbors;
        bool isLeaf() const{
            return neighbors.size() == 1;
        }
    };
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> buf1;
        vector<int> buf2;
        vector<int>* pbuf1 = &buf1;
        vector<int>* pbuf2 = &buf2;
        
        if (n == 1){
            buf1.push_back(0);
            return buf1;
        }
        
        if (n == 2){
            buf1.push_back(0);
            buf1.push_back(1);
            return buf1;
        }
        
        vector<Node> nodes(n);
        
        for (auto edge : edges){
            nodes[edge.first].neighbors.insert(edge.second);
            nodes[edge.second].neighbors.insert(edge.first);
        }
        
        for (int i = 0; i < n; i++){
            if (nodes[i].isLeaf()){
                buf1.push_back(i);
            }
        }
        
        while(1){
            for (auto i : *pbuf1){
                for (auto n : nodes[i].neighbors){
                    nodes[n].neighbors.erase(i);
                    if (nodes[n].isLeaf()){
                        pbuf2->push_back(n);
                    }
                }
            }
            if (pbuf2->empty()){
                return *pbuf1;
            }
            pbuf1->clear();
            swap(pbuf1, pbuf2);
        }
    }
};
