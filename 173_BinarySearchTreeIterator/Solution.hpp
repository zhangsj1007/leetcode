/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
       // _root = root;
       current = root;
    }

    /** @return whether we have a next smallest number */
    //从整棵树出发，不断返回最小值，而不是从root根开始。
    bool hasNext() {
        /*if (_root == NULL)
            return false;
        TreeNode * t1, *t2;
        t2 = _root;
        t1 = t2->left;
        if (_root->left == NULL)
            return false;
        while(t1->right != NULL){
            t2 = t1;
            t1 = t1->right;
        }
        nextValue = t1->val;
        if (t2 == _root)
            t2->left = t1->left;
        else
            t2->right = t1->left;
        t1->left = _root->left;
        t1->right = _root->right;
        //delete _root;
        _root = t1;
        return true;*/
        while(current){
            stk.push(current);
            current = current->left;
        }
        if (stk.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        /*return nextValue;*/
        TreeNode *p = stk.top();
        stk.pop();
        current = p->right;
        return p->val;
    }
private:
//int nextValue;
//TreeNode *_root;
stack<TreeNode*> stk;
TreeNode* current;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
