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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        stack<TreeNode*> nodeStack;
        if (root == NULL || p == NULL || q == NULL) 
            return NULL;
        TreeNode* t = root;
        
        while(t != NULL){
            path1.push_back(t);
            if (t == p || t == q){
                if (path2.size() == 0)
                    path2 = path1;
                else
                    break;
            }
            if (t->right != NULL)
                nodeStack.push(t->right);
            if (t->left != NULL)
                t = t->left;
            else if (!nodeStack.empty()){
                t = nodeStack.top();
                nodeStack.pop();
                int n = path1.size() - 1;
                while(path1[n]->right != t){
                    path1.pop_back();
                    n--;
                }
            }else
                t == NULL;
        }
        
        //int i = 0;
        //while((path2.size() < i) && (path1.size() < i) && (path1[i] == path2[i]))
        //    i++;
        /*while((path2.size() < i) && (path1.size() < i)){
            if (path1[i] != path2[i])
                break;
            else 
                i++;
        }*/
        //if (path1.size() > path2.size())
            //return path1[i-1];
        //else 
            //return path2[i-1];
        //return path1[i-1];
        int n = path1.size() - path2.size();
        if (n >= 0){
            while(n > 0){
                path1.pop_back();
                n--;
            }
        }else{
            n *= -1;
            while(n > 0){
                path2.pop_back();
                n--;
            }
        }
        
        n = path1.size() - 1;
        for (; n >=0 && (path1[n] != path2[n]); n--);
        return path1[n];
    }
    
};
