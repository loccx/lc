class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        test = ""
        maxLength = 0
        
        for c in list(s):
            print("\n\nc:", c)
            if (c in test):
                test = test[(test.index(c) + 1):]
                print("\nupdating test:", test)
            test+=c
            print("appending c to test:", test)
            maxLength = max(len(test), maxLength)
            print("maxLength:", maxLength, "| test length:", len(test))
        print("\nloop done | maxlength:", maxLength)
        return maxLength

test = Solution()
print(test.lengthOfLongestSubstring("adcbcab"))
