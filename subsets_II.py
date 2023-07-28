class Solution:
    def subsetsWithDup(self, nums):
        res = []
        nums.sort()
        self.dfs(nums, 0, [], res)
        return res

    def dfs(self, nums, index, path, res):
        res.append(path)
        for i in range(index, len(nums)):
            #this buffer, i > index, is just because there are repeat characters allowed, so a repeat character will not be counted as a duplicate but ACTUAL duplicate characters will be skipped.
            if i > index and nums[i] == nums[i-1]:
                continue
            self.dfs(nums, i+1, path+[nums[i]], res)

'''
nums = [4, 4, 4, 1, 4]
test = Solution()
print(test.subsetsWithDup(nums))

index: 0
path: []
res: [[]]


index: 1
path: [1]
res: [[], [1]]


index: 2
path: [1, 4]
res: [[], [1], [1, 4]]


index: 3
path: [1, 4, 4]
res: [[], [1], [1, 4], [1, 4, 4]]


index: 4
path: [1, 4, 4, 4]
res: [[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4]]


index: 5
path: [1, 4, 4, 4, 4]
res: [[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4], [1, 4, 4, 4, 4]]
continuing 4
continuing 4
continuing 4
continuing 4
continuing 4
continuing 4


index: 2
path: [4]
res: [[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4], [1, 4, 4, 4, 4], [4]]


index: 3
path: [4, 4]
res: [[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4], [1, 4, 4, 4, 4], [4], [4, 4]]


index: 4
path: [4, 4, 4]
res: [[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4], [1, 4, 4, 4, 4], [4], [4, 4], [4, 4, 4]]


index: 5
path: [4, 4, 4, 4]
res: [[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4], [1, 4, 4, 4, 4], [4], [4, 4], [4, 4, 4], [4, 4, 4, 4]]
continuing 4
continuing 4
continuing 4
continuing 4
continuing 4
continuing 4
[[], [1], [1, 4], [1, 4, 4], [1, 4, 4, 4], [1, 4, 4, 4, 4], [4], [4, 4], [4, 4, 4], [4, 4, 4, 4]]
'''
