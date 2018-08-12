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
    vector<int> postorderTraversal(TreeNode *root) {
        stack <int> stack2;
        stack <TreeNode *> stack;
        vector <int> v;
        TreeNode * p = root;
        bool flag = true;
        
        if (root == NULL){
            return v;
        }
        
        do{
            while (p != NULL){
                stack.push(p);
                stack2.push(0);
                p = p->left;
            }
            
            if (stack.empty()){
                flag = false;
            }else if (stack2.top() == 0){
                stack2.pop();
                stack2.push(1);
                p = stack.top();
                p = p->right;
            }else{
                p = stack.top();
                stack.pop();
                stack2.pop();
                v.push_back(p->val);
                p = NULL;             //重新回到栈中取数,另一侧已经遍历过1次
            }
        }while (flag);
        
        return v;
    }
};
