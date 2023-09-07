class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        length = len(matrix)
        #Transpose
        for x in range(length):
            for y in range(x, length):
                matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]
            #Reverse it after transpose each row
            matrix[x].reverse()
        """
        Do not return anything, modify matrix in-place instead.
        """

'''
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]

Tranpose:
[1, 4, 7]
[2, 5, 8]
[3, 6, 9]

Reverse:
[7, 4, 1]
[8, 5, 2]
[9, 6, 3]
'''
