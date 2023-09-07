class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        answer = nums
        left_prod = 0
        right_prod = 0
        for pointer in range(len(nums)):
            for x in range(pointer-1):
                left_prod *= nums[pointer]
