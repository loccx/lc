def climbStairs(self, n: int):
        if n < 2:
            return 1
        dp = [1,1]

        k = 2
        while k < n+1:
            dp.append(dp[k-1] + dp[k-2])
            k+=1
        
        return dp[k]