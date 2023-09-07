class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islandCount = 0
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == '1':
                    islandCount += 1
                    dfs()
        return islandCount

    def dfs(self, x, y, grid):
        if grid[x][y] == '1':
            grid[x][y] = '#'
            if x < len(grid) - 1: self.dfs(x+1, y, grid)
            if x > 0: self.dfs(x-1, y, grid) 
            if y < len(grid[0]) - 1: self.dfs(x, y+1, grid)
            if y > 0: self.dfs(x, y-1, grid) 
        return
