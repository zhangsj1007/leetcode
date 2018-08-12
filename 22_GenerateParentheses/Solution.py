'''
算法：使用了dp的算法，先算子结构，然后不断的到子结构中查找，解法很精妙
'''

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        l = [[] for j in range(n+1)]
        l[0].append('')
        
        for i in range(n+1) :
            for j in range(i) :
                #二维表搜索
                l[i] += ['(' + x + ')' + y for x in l[j] for y in l[i - j - 1]]
        return l[n]
