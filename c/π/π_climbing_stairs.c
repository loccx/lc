int climbStairs(int n){
    if (n < 2) { return 1; }

    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int k = 2; k < n; k++) {
        dp[k] = dp[k-1] + dp[k-2];
    }

    return dp[n - 1];
}
