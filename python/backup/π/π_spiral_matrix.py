class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        # store matrix values
        res = []

        # if empty matrix, return empty array
        if len(matrix) == 0:
            return res

        # this is the index of the row that we are in, the FIRST bracket value
        row_begin = 0
        # this is the last possible index
        row_end = len(matrix)-1 

        # this is the index of the column that we are in, the SECOND bracket value
        col_begin = 0
        # this is the last possible index
        col_end = len(matrix[0])-1

        # while the indexes, which we will be decrementing the interval to process the smaller spirals, are within a valid interval, we continue running the for loops
        # while the vertical interval is not zero, and horizontal interval is not zero respectively.
        while (row_begin <= row_end and col_begin <= col_end):
            # iterates over the top ROW, it uses column indexes to represent the front and end of the row.
            # col_end + 1 is necesssary to iterate over the full range since the end of the range is noninclusive
            for i in range(col_begin,col_end+1):
                res.append(matrix[row_begin][i])
            # after processing the top row, it increments the row_begin, effectively restricting the boundaries such that the top wont be processed anymore
            row_begin += 1

            # iterate over the right COLUMN, which uses the newly incremented top restriction (row_begin) and bottom restriction to append all values into the list
            for i in range(row_begin,row_end+1):
                res.append(matrix[i][col_end])
            # when right column is processed, that means we must squash the restriction for the right side pointer, which is the column_end
            col_end -= 1

            # before processing the BOTTOM ROW, it checks if the top row index has already been squashed down to the end of the row, otherwise there is no bottom row to process and it will not touch it.
            if (row_begin <= row_end):
                for i in range(col_end,col_begin-1,-1):
                    res.append(matrix[row_end][i])
                #but if it does process, it is necessary to decrement the bottom row constraint so that we process our columns correctly
                row_end -= 1

            # same thing here, making sure the left column exists. Remember that col_begin represents the left side constraint and col_end represents the right side constraint.
            if (col_begin <= col_end):
                for i in range(row_end,row_begin-1,-1):
                    res.append(matrix[i][col_begin])
                # if left column is processed, then it must be incremented to avoid index out of bounds
                col_begin += 1

        return res

[0, 0, 0, 0]
[0, 0, 0, 0]
[0, 0, 0, 0]
[0, 0, 0, 0]
