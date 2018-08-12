/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        queue<TreeNode *> q;
        int length = 0;
        ListNode *pL = head;
        int i = 1;
        TreeNode *p1 = NULL;
        TreeNode *p2 = NULL;
        TreeNode * root = NULL;
        
        while(pL != NULL){
            length++;
            pL = pL->next;
        }
       //首先要判断输入不存在的情况。
       if (head == NULL) {
            return root;
        }
        
        
        root = new TreeNode(0);
        q.push(root);
        
       
        //通过一个queue建造BST
        while(1){
            p1 = q.front();
            q.pop();
            
            if (i == length){
                break;
            }
            
            p2 = new TreeNode(0);
            p1->left = p2;
            i++;
            q.push(p2);
            if (i == length){
                break;
            }
            
            p2 = new TreeNode(0);
            p1->right = p2;
            i++;
            q.push(p2);
        }
        
        pL = head;
        //通过中序遍历将值添加进BST中
        stack<TreeNode *> stack;
        TreeNode * p = root;
        bool flag = true;

        while(flag){
            while(p != NULL){
                stack.push(p);
                p = p->left;
            }
            
            if (stack.empty()){
                flag = false;
            }else{
                p = stack.top();
                stack.pop();
                p->val = pL->val;
                pL = pL->next;
                p = p->right;
            }
        }
        
        return root;
        
        
    }
};
