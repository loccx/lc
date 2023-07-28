class Solution:
    def orangesRotting(grid):
        rows = len(grid)
        if rows == 0: #empty case
            return -1
        cols = len(grid[0])

        rotten = []
        totalOranges = 0
        
        for n in range(rows):
            for m in range(cols):
                if grid[n][m] == 2:
                    rotten.append((n,m))
                    totalOranges += 1
                elif grid[n][m] == 1:
                    totalOranges += 1

        rotOrange = appended = len(rotten)
        temp = 0
        minutes = 0
        for x, y in rotten:
            for dx,dy in (-1,0),(1,0),(0,1),(0,-1):
                checkR = x+dx
                checkC = y+dy
                if 0<= checkR <rows and 0<= checkC <cols and grid[checkR][checkC] == 1:
                    grid[checkR][checkC] = 2
                    rotOrange += 1
                    rotten.append((checkR, checkC))
                    temp+=1

            appended -=1
            if appended == 0:
                appended = temp
                temp = 0
                if not (x, y) == rotten[-1]:
                    minutes += 1
        if rotOrange == totalOranges:
            return minutes
        else:
            return -1

test = Solution
print(test.orangesRotting([[2,1,1],
                           [1,1,0],
                           [0,1,1]]))