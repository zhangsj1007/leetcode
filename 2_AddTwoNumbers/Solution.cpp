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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {            
        ListNode* res = NULL;
        ListNode* last = NULL;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        int r = 0;
        
        while (t1 != NULL && t2 != NULL){
            int i1 = t1->val;
            int i2 = t2->val;
            
            int ii = i1 + i2 + r;
            
            r = ii / 10;
            ii = ii % 10;
            
            
            ListNode * node = new ListNode(ii);
            if (res == NULL){
                res = node;
                last = node;
            }else {
                last->next = node;
                last = node;
            }
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        t1 = t1 != NULL ? t1 : t2;
        
        while (t1 != NULL){
            int i1 = t1->val;
            
            int ii = i1 + r;
            
            r = ii / 10;
            ii = ii % 10;
           
            ListNode * node = new ListNode(ii);
            last->next = node;
            last = node;
            
            t1 = t1->next;
        }
        
        if (r != 0){
            ListNode * node = new ListNode(r);
            last->next = node;
        }
        
        
        return res;
    }
    
};
