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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int length;
        int n;
        ListNode * pNode = head;
        ListNode * p = NULL;
        vector<ListNode *> vec;
        
        length = Length(head);
        n = length / k;
        
        if (n == 0)
            return head;
            
        for (int i = 0; i < n; i++){
            ListNode * pReverse = pNode; 
            for(int j = 0; j < k - 1; j++){
                pNode = pNode->next;
            }
    
            p = pNode->next;
            pNode->next = NULL;
            ListNode* new1 = Reverse(pReverse);
            vec.push_back(new1);
            pNode = p;
        }
        
        
        
        
        
        ListNode * pHead = vec[0];
        
        ListNode * pTemp = NULL;
        for (int i = 0; i < vec.size(); i++){
            pTemp = vec[i];
            while (pTemp->next != NULL)
                pTemp = pTemp->next;
            if (i < vec.size() - 1)
                pTemp->next = vec[i + 1];
        }
        
        
        
        pTemp->next = pNode;
        return pHead;
    }
    
    ListNode * Reverse(ListNode *head){
        ListNode * reverseHead = NULL;
        ListNode * pNode = head;
        ListNode * pPrev = NULL;
        while(pNode != NULL){
            ListNode * pNext = pNode->next;
            if (pNext == NULL)
                reverseHead = pNode;
                
            pNode->next = pPrev;
            
            pPrev = pNode;
            pNode = pNext;
        }
        return reverseHead;
    }
    
    int Length(ListNode * pNode){
        int length = 0;
        while (pNode != NULL){
            length++;
            pNode = pNode->next;
        }
        return length;
    }
};
