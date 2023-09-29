class Solution:
    def imageSmoother(self, img):
        if not img:
            return

        result = list(img)

        def smooth(x, y):
            cellCount = 0
            total = 0
            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    newRow = x + dx
                    newCol = y + dy
                    if 0 <= newRow < len(img) and 0 <= newCol < len(img[0]):
                        cellCount += 1
                        total += img[newRow][newCol]
            result[x][y] = total // cellCount
            print(img)
            print(result)

        for row in range(len(img)):
            for col in range(len(img[0])):
                smooth(row, col)
        return result

test = Solution()
image = [[100,200,100],[200,50,200],[100,200,100]]
print(test.imageSmoother(image))
