class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        # dp array of all 1's
        dp=[1]*len(nums)

        # iterates backwards through the list of numbers
        for i in range(len(nums)-1,-1,-1):
            # iterate through each value above the current selected index
            # that is why it starts at i+1
            for j in range(i+1,len(nums)):
                # if a value is greater than the current one ... 
                if nums[i]<nums[j]:
                    # ... then the dp array stores a count of all the values that are strictly larger than the current one
                    dp[i]=max(dp[i],1+dp[j])

        # finally it takes the maximum of the dp array
        return max(dp)
