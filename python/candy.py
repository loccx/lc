'''
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
 
You are giving candies to these children subjected to the following requirements:
 
    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
 
Return the minimum number of candies you need to have to distribute the candies to the children.
'''

class Solution:
    def candy(self, ratings):
        n = len(ratings)
        val = [1] * n

        for k in range(1, n):
            if ratings[k] > ratings[k-1]:
                val[k] = val[k-1] + 1

        for k in range(n-2, -1, -1):
            if ratings[k] > ratings[k+1] and val[k] <= val[k+1]:
                val[k] = val[k+1] + 1
        print(val)

        return sum(val)

test = Solution()
ratings = [1, 0, 2]
print(test.candy(ratings))
