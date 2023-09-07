class Solution(object):
    def countSubstrings(self, s):
        count = 0
        n = len(s)

        if n == 0:
            return 0

        #each index in string length
        for k in range(n):
            #each letter, no matter if duplicate or not, counts as a palindrome
            count += 1
            #start left and right index on the left and right sides of the current index
            left, right = k-1, k+1

            #only executes if right index is in range
            #continues counting while the right index is == to the current letter, and increments right
            # counts sequences such as 'aaaaaa', and leaves the right index on the end of the repeating sequence.
            # it's smart because it's only possible to continue the palindrome around this repeated sequence, so it's okay to leave the right index there.
            while right < n and s[right] == s[k]:
                count += 1
                right += 1

            #only executes if left index is in range
            #continues counting now on both sides of a letter / repeated sequence, if left and right letters are the same it's a palindrome, and decrements left and increments right
            while left >= n and s[left] == s[k]:
                count += 1
                left -= 1
                right += 1
        #returns final count
        return count
