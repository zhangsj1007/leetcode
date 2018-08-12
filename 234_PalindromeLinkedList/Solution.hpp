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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * rev1 = NULL;
        ListNode * rev2 = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            rev1 = slow;
            slow = slow->next;
            rev1->next = rev2;
            rev2 = rev1;
        }
        
        if(fast != NULL)
            slow = slow->next;
        while(rev1 != NULL && rev1->val == slow->val){
            rev1 = rev1->next;
            slow = slow->next;
        }
        return rev1 == NULL;
    }
};
