class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
    # dp[i] := fewest # Of coins to make up i
    # i is both the amount and the index in the dp array. notice how the index and some target are usually related in dp.
    # start with 0 because you need 0 coins to make up an amount of 0
    # for amount of 11, we have [0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
    # IMPORTANT: amount + 1 is used over amount because it is impossible to need amount + 1 number of coins for an amount, since the lowest value of a coin is 1 so the minimum will be amount # of coins. This impossible count is overrode by calculated values.
    dp = [0] + [amount + 1] * amount

    # for each coin value in coins:
    for coin in coins:
        # for each value ranging from one coin value to the amount + 1
        for i in range(coin, amount + 1):
            # we take the minimum at each index/amount because if a coin hits it, we want either the existing # of coins it took or the # of times it took for the last occurence of the coin + 1, where + 1 is the current coin again
            dp[i] = min(dp[i], dp[i - coin] + 1)

    # it returns -1 if the dp[amount] is amount + 1 because that means the coins iterating never modified the final index
    return -1 if dp[amount] == amount + 1 else dp[amount]

'''
amount = 11
coins = [1, 2, 5]
dp = [0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
dp = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
dp = [0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6]
dp = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]

coins = [5, 2, 1]
dp = [0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]
dp = [0, 12, 12, 12, 12, 1, 12, 12, 12, 12, 2, 12]
dp = [0, 12, 1, 12, 2, 1, 3, 2, 4, 3, 2, 4]
dp = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]
'''
