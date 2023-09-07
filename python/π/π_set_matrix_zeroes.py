class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # set data structures to store indexes
        row = set()
        column = set()
        
        rows, cols = len(matrix), len(matrix[0])
        #for each index in the graph
        for i in range(rows):
            for j in range(cols):
                #if graph[i][j] == 0, then add the indexes to the set
                if matrix[i][j] == 0:
                    row.add(i)
                    column.add(j)          

        # fixes the column value and iterates across all row values, setting them to 0 
        for i in row:
            for j in range(cols):
                matrix[i][j] = 0

        # fixes the row value and iterates across all column values, setting them to 0 
        for i in column:
            for j in range(rows):
                matrix[j][i] = 0 
