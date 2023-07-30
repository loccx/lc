class Solution:
    def wordBreak(self, s, wordDict):

        # List of False initialized for each letter in the string, +1 so that when dp is done running the final index is saved just for the boolean result
		dp = [False]*(len(s)+1)
        # because an empty string will always be True, it is the starter point for the dp
        dp[0] = True

        # pointer iterates through each index, this will represent the END of the substring.
        for i in range(1, len(s)+1):
            # pointer iterates through each index up to ^ that index, this will represent the BEGINNING of the substring
            for j in range(i):
                # if the index is true, and the selected substring is in the dictionary
                # it is important to catch that s[j:i], on the final iteration, the dp[i] is an extra index just for the result, and the actual string is processed from j to i, noninclusive of the ith index.
                if dp[j] == True and s[j:i] in wordDict:
                    # then it sets the end of the word to True, so that the next BEGINNING index will always be at the index of the end of the current word plus 1.
                    # this sets the index AFTER the end of the previous word.
					dp[i] = True
                    # we break out of the innder loop, since if the current substring is a word, there are no other words possible within the word.
                    break

        # when everything ran smoothly, the final index should be set to true, since we left the extra index for the dp conditionals to set it to True
        return dp[-1]

'''
s = 'leetcode'
wordDictionary = ['leet', 'code']
[False, ]
'''
    
'''
    
It initializes a dynamic programming (DP) array "dp," where each element "dp[i]" represents whether the substring "s[:i]" can be segmented into words from the dictionary.
    
It sets "dp[0] = True" because an empty string can always be segmented into an empty sequence of words.
    
The function iterates over each index "i" from 1 to the length of the input string "s" + 1. For each "i," it checks all the possible substrings from "s[j:i]" where "j" varies from 0 to "i."
    
If "dp[j] = True" (indicating that the substring "s[:j]" can be segmented) and the substring "s[j:i]" exists in the "wordDict," then it sets "dp[i] = True," indicating that the substring "s[:i]" can be segmented.
    
The function returns the value of "dp[-1]," which represents whether the entire string "s" can be segmented into words from the "wordDict."
    
'''
