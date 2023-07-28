class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        for n in set(ransomNote):
            if ransomNote.count(n) > magazine.count(n):
                return False
        return True
            