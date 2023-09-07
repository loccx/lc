class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s1, s2 = [], []

        for letter in s:
            if letter == '#':
                s1.pop()
            else:
                s1.append(letter)

        for letter in t:
            if letter == '#':
                s2.pop()
            else:
                s2.append(letter)
        return s1 == s2
