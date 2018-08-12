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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *pNodeA = headA;
        ListNode *pNodeB = headB;
        int nLengthA = GetLength(headA);
        int nLengthB = GetLength(headB);
        int diffLength = 0;
        if (nLengthA > nLengthB)
            diffLength = nLengthA - nLengthB;
        else
            diffLength = nLengthB - nLengthA;
        if (nLengthA > nLengthB) 
            while(diffLength > 0){
                pNodeA = pNodeA->next;
                diffLength--;
            }
        else
            while(diffLength > 0){
                pNodeB = pNodeB->next;
                diffLength--;
            }
        while (pNodeA != NULL && pNodeB != NULL && pNodeA != pNodeB){
            pNodeA = pNodeA->next;
            pNodeB = pNodeB->next;
        }
        if (pNodeA != NULL && pNodeB != NULL)
            return pNodeA;
        else
            return NULL;
    }
    int GetLength(ListNode *pHead){
        ListNode *pNode = pHead;
        int count = 0;
        while (pNode != NULL){
            pNode = pNode->next;
            count++;
        }
        return count;
    }
};
