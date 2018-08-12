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
    bool isSymmetric(TreeNode *root) {
        
        if (root == NULL){
            return true;
        }
        
        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)){
            return false;
        }
        
        vector<TreeNode *> deq;
        TreeNode * p = NULL;
        int rear = 0;
        int front = 0;
        int level = 0;
        deq.push_back(root);
        rear++;
        level = rear;
        int i, j;
        
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
                if ((rear - front) & 1){ // 有奇数个子结点
                    return false;
                }        
                
                for(i = front, j = rear - 1; i < j; i++, j--){
                    if((deq[i]->left != NULL && deq[j]->right == NULL) || (deq[i]->left == NULL && deq[j]->right != NULL) || 
                    (deq[i]->val != deq[j]->val)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
