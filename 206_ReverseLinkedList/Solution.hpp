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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = NULL;
        ListNode *rHead = NULL;
        ListNode *pNext = NULL;
        
        while(p1 != NULL){
               if (p1->next == NULL){
                   rHead = p1;
               }
               pNext = p1->next;
               p1->next = p2;
               
               p2 = p1;
               p1 = pNext;
        }
        
        return rHead;
    }
};
