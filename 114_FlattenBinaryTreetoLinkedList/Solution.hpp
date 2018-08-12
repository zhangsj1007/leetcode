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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* p1 = root;
        TreeNode* p2 = root;
        stack<TreeNode*> s;
        
        while(p1 != NULL){
            if (p1->right != NULL)
                s.push(p1->right);
            p2 = p1;
            p1 = p1->left;
            if (p1 == NULL && !s.empty()){
                p1 = s.top();
                s.pop();
            }
            visit(p2, p1);
        }
    }
    //必须要有2个指针
    void visit(TreeNode * r1, TreeNode * r2){
        r1->left = NULL;
        r1->right = r2;
    }
};
