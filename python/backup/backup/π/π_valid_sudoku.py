class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        result = []
        for x in range(len(board)):
            for y in range(len(board[0])):
                curr = board[x][y]
                if curr != '.':
                    result += [(x, curr), (curr, y), (curr, x // 3, y // 3)]
        return len(result) == len(set(result))
