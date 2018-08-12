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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<TreeNode *> deq;
        vector<int> v;
        vector<vector<int> > vV;
        TreeNode *p = NULL;
        
        if (root == NULL){
            return vV;
        }
        
        int front = 0;
        int rear = 0;
        int level = 0;
        v.push_back(root->val);
        vV.push_back(v);
        deq.push_back(root);
        rear++;
        level++;
        while (front < rear){
            p = deq[front];
            front++;
            if (p->left != NULL){
                deq.push_back(p->left);
                rear++;
            }
            if (p->right != NULL){
                deq.push_back(p->right);
                rear++;
            }
            
            if (front == level){
                level = rear;
                v.clear();
                for (int i = front; i < rear; i++){
                    v.push_back(deq[i]->val);
                }
                vV.push_back(v);
            }
        }
         vV.pop_back();
         return vV;
    }
};
