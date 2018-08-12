/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> nodeStk;
        TreeNode * step1 = NULL;
        TreeNode * step2 = NULL;
        TreeNode * falt1 = NULL;
        TreeNode * falt2 = NULL;
        TreeNode * node = NULL;

        node = root;
        while(true){
            while(node != NULL){
                nodeStk.push(node);
                node = node->left;
            }
            if (nodeStk.empty()){
                break;
            }
            node = nodeStk.top();
            nodeStk.pop();
            if (step1 == NULL){
                step1 = node;
            }else{
                step2 = step1;
                step1 = node;
                if (step2->val > step1->val){
                    if (falt1 == NULL){
                        //the situation that in the sequence the neighbouring nodes exchanges
                        falt1 = step2;
                        falt2 = step1;
                    }else{
                        falt2 = step1;
                        break;
                    }
                }
            }
            node = node->right;
        }
        swapVal(falt1, falt2);
    }
    
    void swapVal(TreeNode * node1, TreeNode * node2){
       if (node1 == NULL || node2 == NULL)
            return;
        int t = node1->val;
        node1->val = node2->val;
        node2->val = t;
    }
};
