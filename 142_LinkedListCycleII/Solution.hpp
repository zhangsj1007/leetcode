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
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * detected = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (detected == slow){
                return detected;
            }
            if (fast == slow){              //fast == slow代表检查完一圈。
                detected = detected->next;
            }
        }
        
        return NULL;
    }
};
