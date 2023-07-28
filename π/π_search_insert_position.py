class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        nums.sort()
        if target > nums[-1]:
            return len(nums)
        if target < nums[0]:
            return 0

        x = 0
        while target > curr:
            curr = nums[x]
            x += 1
        return x

