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
    ListNode* sortList(ListNode* head) {
       if(head == NULL || head->next == NULL)
            return head;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
    
    ListNode * merge(ListNode * head1, ListNode * head2){
        ListNode dummy(0);
        ListNode * current = &dummy;
        while (head1 && head2){
            if (head1->val < head2->val){
                current->next = head1;
                head1 = head1->next;
            }else{
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        current->next = head1 ? head1 : head2;
        return dummy.next;
    }
};
