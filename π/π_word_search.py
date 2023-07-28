class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        #iterate across each one in the board
        for i in range(len(board)):
            for j in range(len(board[i])):
                # make dfs call for each item in the board
                # dfs call returns true if the word is contained in the graph
                if self.backtracking(i, j,word,board):
                    return True
        # if nothing is called after entire grid is processed, then has to be false
        return False

    def backtracking(self,i, j,word,board):
            # damn lowkey you were close; take one letter of the owrd each dfs call, and it only takes letter off if the letter existed, so down the line when it returns true the whole thing is true
            if len(word) == 0:
                return True

            # if dfs call goes out of bounds, instant false, and don't continue dfs calls
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[i]):
                return False

            # if the current letter is the same as the first letter in the word, then erase it to something random so dfs calls are not repeated
            if board[i][j] == word[0]:
                # you need to set this to some random character so that it doens't get called again, otherwise you will find invalid answers.
                board[i][j] = "~"

                #if any of these recursive calls are true, then the calls keep going until the word disappears, and then we know that the entire word is found.
                if self.backtracking(i+1, j, word[1:],board) or
                self.backtracking(i-1, j, word[1:],board) or
                self.backtracking(i, j+1, word[1:],board) or
                self.backtracking( i, j-1, word[1:],board):
                    return True

                #however, if none of them executed, then we have to put the leter back to what it was; think about this more, it doens't make sense right now
                board[i][j] = word[0]

            # if none of the backtracking was true, then it has to be false
            return False
