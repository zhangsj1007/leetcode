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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode * pOdd1 = head;
        ListNode * pEven1 = head->next;
        ListNode * pOdd2 = head->next->next;
        ListNode * pEven2 = head->next;
        do{
            pOdd1->next = pOdd2;
            pEven2->next = pOdd2->next;
            pOdd2->next = pEven1;
            
            if (pEven2->next != NULL && pEven2->next->next !=NULL){
                pOdd1 = pOdd1->next;
                pEven2 = pEven2->next;
                pOdd2 = pEven2->next;
            }else
                break;
            
        }while(1);
        
        return head;
    }
};
