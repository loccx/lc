class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProf = 0
        left, right = 0, 1

        while right < len(prices):
            if prices[right] < prices[left]:
                left = right
                right
            currProf = prices[right] - prices[left]
            maxProf = max(maxProf, currProf)
            right+=1
        return maxProf
