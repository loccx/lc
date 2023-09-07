class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        self.dfs(digits, [], result)
        return result
    
    def dfs(self, digits, path, result):
        if not digits:
            result.append(''.join(path))
            return
        mapping = {'2': ['a', 'b', 'c'], '3': ['d', 'e', 'f'], '4': ['g', 'h', 'i'], '5': ['j', 'k', 'l'], '6': ['m', 'n', 'o'], '7': ['p', 'q', 'r', 's'], '8': ['t', 'u', 'v'], '9': ['w', 'x', 'y', 'z']}

        for digit in range(len(mapping[digits[0]])):
            self.dfs(digits[1:], path + [mapping[digits[0]][digit]], result)
