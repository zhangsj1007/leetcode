class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        temp = []
        res = []
        res1 = []
        candidates = sorted(candidates)
        self.calculate(candidates, target, res, temp)
        return res            
        
    def calculate(self, candidates, target, res, temp) :
        #检查target为0的同时，需要检查重复
        if target == 0 and temp not in res:
            res += [temp] 
            
        for index, i in enumerate(candidates) :
            if target >= i :
                self.calculate(candidates[index+1:], target-i, res, temp+[i])
        
        
        
