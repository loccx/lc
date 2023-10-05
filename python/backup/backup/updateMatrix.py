class Solution:
    def updateMatrix(mat):
        rows = len(mat)
        cols = len(mat[0])
        q = []

        for n in range(rows):
            for m in range(cols):
                if mat[n][m] == 0:
                    q.append((n,m))
                else:
                    mat[n][m] = '#'
        
        for r,c in q:
            for dx, dy in (1,0),(-1,0),(0,1),(0,-1):
                nr = r+dx
                nc = c+dy
                if 0 <= nr < rows and 0 <= nc < cols and mat[nr][nc] == '#':
                    mat[nr][nc] = mat[r][c] + 1
                    q.append((nr, nc))
        return mat

test = Solution
print(test.updateMatrix([[0,0,0],[0,1,0],[1,1,1]]))

'''
[[1, 1, 1],
 [1, 1, 1], 
 [0, 1, 1]]

 output:
 [[2, 3, 4],
  [1, 2, 3], 
  [0, 1, 2]]
'''