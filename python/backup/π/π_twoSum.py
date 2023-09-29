class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]
        pairs = {}
        # gets the index and value of each item in the array
        for index, value in enumerate(nums):
            remaining = target - nums[index]

            if remaining in pairs:
                return [index, pairs[remaining]]
            else:
                pairs[value] = index
