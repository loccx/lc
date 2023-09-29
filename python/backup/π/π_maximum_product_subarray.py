class Solution:
    def maxProduct(self, nums):
        dp = [0 for k in len(nums)]

        minProduct = nums[0]
        maxProduct = nums[0]

        maximumResult = maxProduct

        for k in range(1, len(nums)):
            if nums[k] < 0:
                minProduct, maxProduct = maxProduct, minProduct
            
            maxProduct = max(nums[k], maxProduct * nums[k])
            minProduct = min(nums[k], minProduct * nums[k])

            maximumResult = max(maximumResult, maxProduct)
        return maximumResult
