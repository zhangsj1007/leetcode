class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        buf = [(0, len(s))] * 26
        base = ord('a')
        for i in range(len(s)):
            offset = ord(s[i]) - base
            cnt , p = buf[offset]
            buf[offset] = cnt+1, min(i, p)
        try:
            return min([p for cnt, p in buf if cnt == 1])
        except ValueError:
            return -1
        
