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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL){
            return NULL;
        }
        
        ListNode h(0);
        ListNode *p1 = NULL;
        ListNode *p2 = NULL;
        ListNode *p = NULL;
        int flag = 0;
        
        h.next = head;
        p = &h;
        
        p1 = head;
        
        while (p1 != NULL){
            p2 = p1->next;
            
            while (p2 != NULL && p2->val == p1->val){
                flag = 1;
                p1->next = p2->next;
                delete(p2);
                p2 = p1->next;
            }
            
            if (flag == 1){
                p->next = p1->next;
                delete(p1);
                p1 = p->next;
                flag = 0;
            }else{
                p = p->next;
                p1 = p->next;
            }
        }
        return h.next;
    }
};
