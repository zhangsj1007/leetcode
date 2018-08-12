/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        vector<TreeLinkNode *> deq;   //用vector模拟一个栈
        vector<TreeLinkNode *>v;
        vector<vector<TreeLinkNode*> > vV;
        TreeLinkNode * p = NULL;
        int front = 0;
        int rear = 0;
        int level = 0;
        deq.push_back(root);
        v.push_back(root);
        vV.push_back(v);
        rear++;
        level = rear;
        while(front < rear){
            p = deq[front];
            front++;
            if (p->left != NULL){
                deq.push_back(p->left);
                rear++;
            }
            if (p->right != NULL){
                deq.push_back(p->right);
                rear++;
            }
            if (front == level){ //一层遍历完的标志
                level = rear;
                v.clear();
                for(int i = front; i < rear; i++){ //将二叉树一层的元素存于一个vector中
                    v.push_back(deq[i]);
                }
                vV.push_back(v);
            }
        }
       for (int i = 0; i < vV.size() - 1; i++){
            v = vV[i];
            for (int j = 0; j < v.size(); j++){
                if (j == v.size() - 1){
                    v[j]->next = NULL;
                }else{
                    v[j]->next = v[j+1];
                }
            }
        }
    }
};
