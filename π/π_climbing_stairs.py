class Solution:
    def climb(n):
        if n == 0: return 0
        if n == 1: return 1
        if n == 2: return 2

        dp = [0] * (n + 1)
        dp[1], dp[2] = 1, 2

        for x in range(3, n + 1):
            dp[x] = dp[x-1] + dp[x-2]
        
        return dp[n]
