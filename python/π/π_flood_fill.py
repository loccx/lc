class Solution:
    def floodFill(self, image, sr, sc, color):
        originalColor = image[sr][sc]
        if image[sr][sc] == color:
            return image

        maxX, maxY = len(image), len(image[0])

        def dfs(x, y):
            if image[x][y] == originalColor:
                image[x][y] = color
                if x < maxX - 1: dfs(x+1, y)
                if x > 0: dfs(x-1, y)
                if y < maxY - 1: dfs(x, y+1)
                if y > 0: dfs(x, y-1)

        dfs(sr, sc)

        return image

