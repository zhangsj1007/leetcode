/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL){
            return NULL;
        }
        RandomListNode *p = head;
        RandomListNode *p1 = NULL;
        RandomListNode *newHead = NULL;
        
        while (p != NULL){
            p1 = new RandomListNode(p->label);
            p1->next = p->next;
            p->next = p1;
            p = p->next->next;
        }
        
        p = head;
 
        while(p != NULL){
            p1 = p->next;
            if (p->random == NULL){
                p1->random = NULL;
            }else{
                p1->random = p->random->next;
            }
            p = p->next->next;
        }
        
        p = head;
        newHead = p->next;
        
        while(1){
            p1 = p->next;
            if (p1->next != NULL){
                p->next = p1->next;
                p1->next = p->next->next;
                p = p->next;
            }else{
                p->next = NULL;
                break;
            }
        }
        return newHead;
    }
};
