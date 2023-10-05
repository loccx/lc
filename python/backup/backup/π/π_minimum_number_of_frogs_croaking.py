'''
You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
'''

class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        count = {'c' : 0, 'r' : 0, 'o' : 0, 'a' : 0, 'k' : 0}

        answer = 0

        for char in croakOfFrogs:
            if char not in count:
                return -1
            count[char] += 1
            if count['c'] < count['r'] or count['r'] < count['o'] or count['o'] < count['a'] or count['a'] < count['k']:
                return -1
            answer = max(answer, count['c'] - count['k'])
        if count['c'] == count['r'] == count['o'] == count['a'] == count['k']:
            return answer
        return -1
