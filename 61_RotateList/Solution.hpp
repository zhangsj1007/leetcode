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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k < 0)
            return NULL;
        int length = LengthOfList(head);
        
        if (length < k){
            k = k % length;
        }
        if (length == k || k == 0){
            return head;
        }
        
        ListNode * p = head;
        ListNode * p2 = head;
        ListNode * p3 = head;
        ListNode * newH = NULL;
        for(int i = 0; i < k - 1; i++){
            p = p->next;
        }
        while(p->next != NULL){
            p3 = p2;
            p2 = p2->next;
            p = p->next;
        }
        newH = p2;
        p->next = head;
        p3->next = NULL;
        return newH;
    }
    int LengthOfList(ListNode *head){
        int length = 0;
        ListNode * p =head;
        while(p!= NULL){
            p = p->next;
            length++;
        }
        return length;
    }
    
};
