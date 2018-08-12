/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int ret = head.val;
        ListNode p = head.next;
        int n = 2;
        while(p != null){
            int m = getRandomInt(1, n++);
            if (m == 1){
                ret = p.val;
            }
            p = p.next;
        }
        return ret;
    }
    
    private int getRandomInt(int start, int end){
        return (int)(start + Math.random() * (end - start + 1));
    }
    
    private ListNode head = null;
    
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
