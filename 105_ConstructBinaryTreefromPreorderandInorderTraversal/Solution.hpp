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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return NULL;
        int index = 0;
        TreeNode * root = new TreeNode(preorder[0]);
        stack<TreeNode*> nodeStk;
        nodeStk.push(root);
        for (int i = 1 ; i < preorder.size(); i++){
            TreeNode * cur = nodeStk.top();
            if (nodeStk.top()->val != inorder[index]){
                cur->left = new TreeNode(preorder[i]);
                nodeStk.push(cur->left);
            }else{
                while(!nodeStk.empty() && nodeStk.top()->val == inorder[index]){
                    cur = nodeStk.top();
                    nodeStk.pop();
                    index++;
                }
                if (index < inorder.size()){
                    cur->right = new TreeNode(preorder[i]);
                    nodeStk.push(cur->right);
                }
            }
        }
        return root;
    }
};
