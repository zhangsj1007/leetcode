class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if k == 0 or length <= 1:
            return 0
        maxProfit = 0
        if (k >= length / 2 ) :
            for i in range(1, length):
                maxProfit += max(prices[i] - prices[i-1] , 0)
            return maxProfit
            
        #[buy,sell],当输入是1G的时候，需要至少8g内存
        a = [[float('-inf'), 0] for i in range(k)]
        for price in prices :
            for i in range(k) :
                if i == 0:
                    a[i][0], a[i][1] = max(a[i][0], -price), max(a[i][1], a[i][0]+price)
                else :
                    a[i][0], a[i][1] = max(a[i][0], a[i-1][1] - price), max(a[i][1], a[i][0]+price)
        return a[-1][1]
        
                    
        
        
        
