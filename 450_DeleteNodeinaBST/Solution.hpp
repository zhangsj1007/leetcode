/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //date: 2017-1-10
 //desc: 3
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = root;
        TreeNode* parent = root;
        while(p != NULL){
            if (p->val > key){
                parent = p;
                p = p->left;
            }else if (p->val < key){
                parent = p;
                p = p->right;
            }else{
                if (p->right == NULL){
                    if (p == root){
                        root = p->left;
                    }else{
                        if(parent->left == p)
                            parent->left = p->left;
                        else
                            parent->right = p->left;
                    }
                }else
                    handleRight(p);
                break;
            }
        }
        return root;
    }
private:
    void handleRight(TreeNode* p){
        TreeNode * t = p->right;
        if (t->left == NULL){
            p->val = t->val;
            p->right = t->right;
        }else{
            TreeNode * t2 = t;
            while(t->left != NULL){
                t2 = t;
                t = t->left;
            }
            t2->left = t->right;
            p->val = t->val;
        }
    }
};
