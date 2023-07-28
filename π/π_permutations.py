class Solution:
    def permute(self, nums):
        #list to store res
        res = []
        #initial dfs call
        self.dfs(nums, [], res)
        return res

    def dfs(self, nums, path, res):
        if not nums:
            res.append(path)
            return
        #the recursive call removes the element that the for loop is currently on, so recursively will keep removing if you go down one strain, and the selected ones are added to the path before the subsequent recursive call is made, so eventually they are all added to the path in different sequences.
        for i in range(len(nums)):
            print('removed index:', i, 'value:', nums[i])
            print('recursive call array:', nums[:i] + nums[i + 1:])
            self.dfs(nums[:i] + nums[i + 1:], path + [nums[i]], res)

'''
Example: nums = [1, 2]

'''
test = Solution()
print('outcome:', test.permute([1, 2, 3]))
