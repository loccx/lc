class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        s_sort = sorted(s)
        t_sort = sorted(t)
        for n in range(len(s_sort)):
            if s_sort[n] != t_sort[n]:
                return False
        return True
