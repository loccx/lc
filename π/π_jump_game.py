class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxDist = 0
        for index in range(len(nums)):
            #if you can't reach the current index, then you cant reach the end.
            if maxDist < index:
                return False
            #take the maximum distance you can reach possible at each index.
            maxDist = max(index+nums[index], maxDist)
        return True
