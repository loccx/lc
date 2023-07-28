class Solution:
    def longestPalindrome(s):
        gang = set()
        for n in s:
            if n not in gang:
                gang.add(n)
            else:
                gang.remove(n)
        
        if len(gang) != 0:
            return len(s) - len(gang) + 1
        return len(s)

test = Solution
print(test.longestPalindrome())