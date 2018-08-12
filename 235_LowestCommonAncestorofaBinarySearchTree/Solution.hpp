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
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *>v1;
        vector<TreeNode *>v2;
        
        transUntilMeetSpecifiedNode(root, p, v1);
        transUntilMeetSpecifiedNode(root, q, v2);
        return _lowestCommonAncestor(v1, v2);
    }
    
    void transUntilMeetSpecifiedNode(TreeNode* root, TreeNode *p, vector<TreeNode *>&v){
        if (root == nullptr)
            return;
        vector<int> vFlag;
        TreeNode * t = root;
        //post order traverse the BST
        while(1){
            while(t != nullptr){
                v.push_back(t);
                vFlag.push_back(0);
                t = t->left;
            }
            if (v.empty())
                break;
            if (vFlag[vFlag.size() - 1] == 0){
                vFlag.pop_back();
                vFlag.push_back(1);
                t = v[v.size() - 1]->right;
            }else{
                if(v[v.size() - 1] == p)
                    break;
                v.pop_back();
                vFlag.pop_back();
                t = nullptr;
            }
        }
    }
    
    TreeNode * _lowestCommonAncestor(vector<TreeNode *>& v1, vector<TreeNode *>& v2){
        int count = v1.size() > v2.size() ? (v2.size() - 1) : (v1.size() - 1);
        for(; count >= 0 ; count--)
            if (v1[count] == v2[count])
                break;
        if(count >= 0)
            return v1[count];
        else
            return nullptr;
        
    }*/
    TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode * p, TreeNode * q){
        if(root->val == p->val || root->val == q->val)
            return root;
        switch ((p->val > root->val) + (q->val > root->val)){
            case 0:
                return lowestCommonAncestor(root->left, p, q);
                break;
            case 1:
                return root;
                break;
            case 2:
                return lowestCommonAncestor(root->right, p, q);
                break;
        }
    }
};
