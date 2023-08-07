class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # turn the list of numbers into a set
        nums = set(nums)
        # initialize longest streak to be 0 at the moment
        longestStreak = 0

        # for each number in the set
        for x in nums:
            # if a number consecutively below it is in the set 
            if x - 1 in nums:
                currStreak = 1

                # while there is a number consecutively larger than the current one...
                while x + 1 in nums:
                    # increment  the current number and increase the current streak that is being counted
                    x += 1
                    currStreak += 1

                # when the streak ends, hence exiting the while loop, take the max
                longestStreak = max(longestStreak, currStreak)
        return longestStreak
