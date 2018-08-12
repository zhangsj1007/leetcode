/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 /*
* 思路：1.遍历，中序遍历； 2.左子叶，当去遍历一个node的一个分支的时候，当这个node的left不为NULL才有可能有左子叶。
 */
 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = 0;
        stack<TreeNode*> stk;
        TreeNode * node = root;
        bool flag = true;
        bool done = false;
        
        if (node->left != NULL) flag = true;
        else flag = false;
        
        while(!done){
            while (node != NULL){
                stk.push(node);
                node = node->left;
            }
            if (stk.size() > 0){
                node = stk.top();
                stk.pop();
                if (isLeave(node) && flag){
                    sum += node->val;
                }
                if (node->right != NULL){
                    node = node->right;
                    if (node->left != NULL) flag = true;
                    else flag = false;
                }else{
                    node = NULL;
                }
            }else{
               done = true;    
            }
        }
        return sum;
    }
    
    bool isLeave(TreeNode * node){
        if (node->left == NULL && node->right == NULL) return true;
        else return false;
    }
    
};
