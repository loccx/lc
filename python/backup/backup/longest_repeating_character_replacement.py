class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        res = 0
        l = 0

        for r in range(len(s)):
            print("\nr:", r)
            print("char:", s[r])
            count[s[r]] = 1 + count.get(s[r], 0) # increments the count for each character
            print("count of current letter:", count[s[r]])

            if (r - l + 1) - max(count.values()) > k: # while length of the substring - the highest frequency character > k
                count[s[l]] -= 1 # decrements the count of the letter, before moving the left pointer
                print("count[s[l]]:", count[s[l]])
                l+=1 # shift the left pointer, and continues decrementing if the k replaces was not enough to make the string valid, on the shorter substring
                print("l:", l)

            res = max(res, r - l + 1) # +1 is necessary to obtain the actual length of the substring
            print("r - l + 1:", r - l + 1)
            print("res:", res)
        return res

string = "BBBBBAA"
test = Solution()
print(test.characterReplacement(string, 2))

# class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:
#         count = {}
#         maxLen = 0
#         leftPointer = 0

#         for charIndex in range(len(s)):
#             count[s[charIndex]] = count.get(s[charIndex], 0)

#             currLen = charIndex - leftPointer + 1
#             while (currLen) - max(count.values()) > k:
#                 currChar = s[charIndex]
#                 count[currChar] -= 1
#                 leftPointer += 1

#             maxLen = max(maxLen, currLen)
#         return maxLen
