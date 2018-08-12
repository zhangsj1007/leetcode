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
    typedef map<pair<int, int>, vector<TreeNode*> > memo_t;
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0){
            vector<TreeNode*> v;
            return v;
        }
        memo_t memo;
        return gen_trees(1, n, memo);
    }
    vector<TreeNode*> gen_trees(int s, int e, memo_t & memo){
        vector<TreeNode*> v;
        if (s > e){
            v.push_back(NULL);
            return v;
        }
        if (memo.count(make_pair(s, e))){
            return memo[make_pair(s, e)];
        }
        for (int i = s; i <= e; i++){
            vector<TreeNode*> vLeft = gen_trees(s, i-1, memo);
            vector<TreeNode*> vRight = gen_trees(i+1, e, memo);
            for (auto left : vLeft){
                for (auto right : vRight){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    v.push_back(root);
                }
            }
        }
        memo[make_pair(s, e)] = v;
        return v;
    }
};
