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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<TreeNode*> deq;
        TreeNode *temp = NULL;
        vector<int> v;
        vector<vector<int> >vV;
        if (root == NULL){
            return vV;
        }
        int front = 0;
        int level = 0;
        int rear = 0;
        deq.push_back(root);
        rear++;
        level = rear;
        v.push_back(root->val);
        vV.insert(vV.begin(), v);
        
        while(front < rear){
            temp = deq[front];
            front++;
            if (temp->left != NULL){
                deq.push_back(temp->left);
                rear++;
            }
            if (temp->right != NULL){
                deq.push_back(temp->right);
                rear++;
            }
            if (front == level){
                level = rear;
                v.clear();
                for(int i = front; i < rear; i++){
                    v.push_back(deq[i]->val);
                }
                vV.insert(vV.begin(), v);
            }
        }
         
        vV.erase(vV.begin());
        return vV;
    }
};
