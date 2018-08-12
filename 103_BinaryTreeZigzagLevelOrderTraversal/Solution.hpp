/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        TreeNode *p = root;
        int front = 0;
        int rear = 0;
        int level;
        vector <TreeNode *> q;
        vector<int> v;
        vector<vector<int> > vV;
        int i;
        
        if (root == NULL){
            return vV;
        }
        
        q.push_back(p);
        v.push_back(p->val);
        vV.push_back(v);
        rear++;
        level = rear;
        
        while(front < rear){
            p = q[front];
            front++;
            
            if (p->left != NULL){
                q.push_back(p->left);
                rear++;
            }
            
            if (p->right != NULL){
                q.push_back(p->right);
                rear++;
            }
            
            if (front == level){
                level = rear;
                v.clear();
                if (vV.size() & 1 == 1)
                    for (i = rear - 1; i >= front; i--){
                        v.push_back(q[i]->val);
                }else{
                    for (i = front; i < rear; i++){
                        v.push_back(q[i]->val);
                    }
                }
                vV.push_back(v);
            }
        }
        vV.pop_back();
        return vV;
    }
};
