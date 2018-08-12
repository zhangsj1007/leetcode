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
    Solution(): count(0) {}
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* q = NULL;
        bool flag = true;
        while(flag){
            while(p){
                s.push(p);
                p = p->left;
            }
            if (!s.empty()){
                q = s.top();
                s.pop();
                count++;
                if (count == k)
                    return q->val;
                p = q->right;
            }else
                flag = false;
        }
    }
private:
    int count;
};
