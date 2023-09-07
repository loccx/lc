class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # if the array is nonexistent, return nothing
        if not heights:
            return []

        #rows: horizontal jits
        #cols: vertical jits
        rows, cols = len(heights), len(heights[0])

        #create 2d array that is the same size as the graph of all false values
        pacific_visited = [[False] * cols for _ in range(rows)]
        print(pacific_visited)
        atlantic_visited = [[False] * cols for _ in range(rows)]

        #create deque data structures for both pacific and atlantic
        pacific_queue = deque()
        atlantic_queue = deque()

        #for each value in the length of columns
        for col in range(cols):
            #pacific queue appends tuple of 0, and the index of the column that it is on
            # the 0 stands for row 0, since that is what it would be iterating on at least if the graph is not 0
            pacific_queue.append((0, col))
            #atlantic queue appends the tuple of the index of the row that it is one - 1 and the column index that it is on
            atlantic_queue.append((rows-1, col))
            #top border is set True for the pacific queue
            pacific_visited[0][col] = True
            #bottom border is set True for the atlantic queue
            atlantic_visited[rows-1][col] = True

        #same thing for the rows
        # i think this is supposed to set up the graph and the queue for the bfs calls
        for row in range(rows):
            # the 0 stands for column 0, since that is what it would be iterating on at least if the graph is not 0
            pacific_queue.append((row, 0))
            atlantic_queue.append((row, cols-1))
            #left border is set True for the pacific queue
            pacific_visited[row][0] = True
            #right border is set True for the pacific queue
            atlantic_visited[row][cols-1] = True

        def bfs(queue, visited):
            while queue:
                row, col = queue.popleft()
                for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    r, c = row + dr, col + dc
                    if 0 <= r < rows and 0 <= c < cols and not visited[r][c]:
                        if heights[r][c] <= heights[row][col]:
                            visited[r][c] = True
                            queue.append((r, c))

#each ocean has their own borders set to True, and the bfs calls start from there and spread, filling up their own visited array from the border.
        bfs(pacific_queue, pacific_visited)
        bfs(atlantic_queue, atlantic_visited)

#Finally, go through both visited graphs and if both oceans has it as true, then it has successfully flowed to both!add it to the result.
        result = []
        for row in range(rows):
            for col in range(cols):
                if pacific_visited[row][col] and atlantic_visited[row][col]:
                    result.append([row, col])

        return result
