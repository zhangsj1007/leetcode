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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        ListNode * p3 = head;
        
        for (int i = 1; i < n; i++)
            p1 = p1->next;
            
        while(p1->next != NULL){
            p2 = p2->next;
            p1 = p1->next;
        }
        
        if (p3 == p2)
            return head->next;
        
        while(p3->next != p2)
            p3 = p3->next;
        
        p3->next = p2->next;
        p2->next = NULL;
        
        return head;
    }
};
