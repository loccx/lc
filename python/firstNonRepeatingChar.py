class Solution:
    def firstNonRepeatingChar(str):
        counter = {}
        for n in str:
            if n not in counter:
                counter[n] = 0
            counter[n] += 1
        
        for n in str:
            if counter[n] == 1:
                return n
        return '_'

test = Solution
print(test.firstNonRepeatingChar('abcabcabc'))