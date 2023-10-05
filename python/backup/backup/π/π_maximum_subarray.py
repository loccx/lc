class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # current sum set to  0, max sum set to first element in nums
        max_sum, currSum = nums[0], 0
        # for each number in nums
        for num in nums:
            # if adding the new number makes the current sum lower than the current item, then take the current item as the current sum
            curr_sum = max(curr_sum + num, num)
            max(curr_sum, max_sum)

        return max_sum
