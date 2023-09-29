class Solution(object): def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #Array to store answer
        res = []
        #Sort array before running algorithm
        nums.sort()
        #i starts at index 0, only needs to go up to len(nums) - 2 because left and right pointers will take up both those spots
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue

# left index starts at the index to the right of i, and right index starts at the last index
            l, r = i+1, len(nums)-1

# while left is less than right, keep goin (find out why this works)
            while l < r:
                # sum up all three pointers
                s = nums[i] + nums[l] + nums[r]

                # if the sum is negative, that means the values are too small, so move up left pointer
                if s < 0:
                    l +=1 
                # if the sum is positive, that means the values are too big, so move down right pointer
            elif s > 0:
                r -= 1
                # otherwise, the sum must be 0, so add it to the solution.
            else:
                #add all three pointer values into the final array
                    res.append((nums[i], nums[l], nums[r]))
                    #preventing duplicate answers:
                    #continue iteration of the left pointer until the value is different
                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    #same for this
                    while l < r and nums[r] == nums[r-1]:
                        r -= 1
                    #iterate one more time, because without iteration, the pointer stays on the last duplicate of a value
                    l += 1; r -= 1
        return res
