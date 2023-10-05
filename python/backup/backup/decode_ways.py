class Solution:
    def numDecodings(self, s: str) -> int:

        # if the string starts with 0, then it can't be formatted into any letter, since # is different from 0#.
        if s[0] == '0':
            return 0

        n = len(s)
        # dp array of 0's, 1 for each letter in the string
        dp = [0 for _ in range(n + 1)]
        # set first value in dp to 0
        dp[0] = 1

        # for each index in string
        for i in range(1, n + 1):

            # if the previous letter isn't 0, then add the previous value to the current
            if s[i - 1] != '0':
                dp[i] = dp[i - 1]

            # starting from the second index onward, we take the sum of the previous 2 letters..
            if i >= 2:
                x = int(s[i - 2: i])

                # and if the sum is at least a double digit and less than the maximum possible value
                if 10 <= x <= 26:
                    # then we add the number of possible encodings from the previous previous letter to the current
                    dp[i] += dp[i - 2]
        return dp[n]

test = Solution()
input = '11106'
print(test.numDecodings(input))
'''
'11106'

[1, 0, 0, 0, 0]
[1, 1, 0, 0, 0]
[1, 1, 1, 0, 0]
[1, 1, 1, 1, 0]
[1, 1, 1, 1, 1]
'''

