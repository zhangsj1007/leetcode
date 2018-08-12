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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<int> ret;
        
        if (root == NULL){
            return ret;
        }
        
        q1.push(root);

        while(true){
            int num = q1.size();
            int max = INT_MIN;
            for (int i = 0; i < num; i++){
                TreeNode* p = q1.front();
                if (p->val > max){
                    max = p->val;
                }
                q1.pop();
                if (p->left != NULL){
                    q1.push(p->left);
                }
                if (p->right != NULL){
                    q1.push(p->right);
                }
            }
            ret.push_back(max);
            if (q1.size() == 0)
                break;
        }
        
        return ret;
    }
    
    
};
