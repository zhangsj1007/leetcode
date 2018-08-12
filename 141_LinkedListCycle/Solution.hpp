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
    bool hasCycle(ListNode *head) {
        
        ListNode * p1 = head;
        ListNode * p2 = head;
        bool firstTime = true;  //标志位，用来记录第一次进入循环。这样节省好多判断。
        
        while (firstTime || p1 != p2){
            if (p2 == NULL || p2->next == NULL){ //p2应该放在p2->next前面，否则对于｛｝，出现runtime error
                return false;
            }
            
            p1 = p1->next;
            p2 = p2->next->next;
            firstTime = false;
        }
        
        return true;
    }
};
