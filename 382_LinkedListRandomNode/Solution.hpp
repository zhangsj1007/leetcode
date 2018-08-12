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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        int i = 0;
        ListNode * p = head;
        while(p != NULL){
            map_[i++] = p;
            p = p->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int num = map_.size();
        //srand(time(0));
        int n = rand() % num;
        return map_[n]->val;
    }
private:
    map<int, ListNode*> map_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
