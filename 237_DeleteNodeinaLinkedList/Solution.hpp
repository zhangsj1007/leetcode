/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;
        //通过赋值的方式删掉第一个node
        ListNode *p = node->next;
        node->val = p->val;
        node->next = p->next;
        delete p;
    }
};
