class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int t = x;
        int ans = 0;
        while(t > 0){
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans == x;
    }
};
