class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        longestStreak = 0

        for x in nums:
            if x - 1 in nums:
                currnum = x
                currStreak = 1

                while x + 1 in nums:
                    currnum += 1
                    currStreak += 1

                max(longestStreak, currStreak)
        return longestStreak
