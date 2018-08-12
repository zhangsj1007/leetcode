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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL){
            return NULL;
        }
        
        ListNode *p = head;
        ListNode *p1 = head;
        ListNode *p2 = NULL;
        
        while(p->next != NULL){          //需要插入头结点前
            if (p1->val > p->next->val){    
                p2 = p->next;              
                p->next = p2->next;
                head = p2;
                p2->next = p1;
                p1 = head;
                continue;
            }
            
            while(p1->next != p->next){
                if (p1->next->val > p->next->val){      //需要插入list中间
                    p2 = p->next;
                    p->next = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    p1 = head;
                    break;
                }else{
                    p1 = p1->next;
                }
            }
            
            if (p1->next == p->next){                    //没有插入的情况。
                p1 = head;
                p = p->next;
            }
        }
        return head;
    }
};
