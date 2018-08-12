class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        if input.isdigit() :
            return [int(input)]
        res = []
        for i in xrange(len(input)) :
            if input[i] in "+-*" :
                res1 = self.diffWaysToCompute(input[:i])
                res2 = self.diffWaysToCompute(input[i+1:])
                res += [eval(str(j)+input[i]+str(k)) for j in res1 for k in res2]
        return res
