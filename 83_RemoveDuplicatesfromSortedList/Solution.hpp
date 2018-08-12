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
        if (head == NULL)
            return NULL;
        sameValue = head->val;
        ListNode * pNode = head->next;
        ListNode * pPre = head;
        ListNode * pTemp = NULL;
        while(pNode != NULL){
            /*if(pNode->next->val == sameValue){
                pTemp = pNode->next->next;
                delete(pNode->next);
                pNode->next = pTemp;
            }else{
                sameValue = pNode->next->val;
            }*/
            if (pNode->val == sameValue){
                pTemp = pNode->next;
                delete(pNode);
                pPre->next = pTemp;
            }else{
                sameValue = pNode->val;
                pPre = pPre->next;
            }
            
            pNode = pPre->next;
        }
        return head;
    }
    Solution(int sameValue = 0){};
private:
    int sameValue;
};
