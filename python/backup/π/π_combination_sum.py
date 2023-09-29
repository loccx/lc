class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        #candidates = [2, 3, 4, 7]
        candidates.sort()
        #start dfs call that updates the result
        self.dfs(candidates, target, 0, [], result)
        return result

    def dfs(self, nums, target, index, path, result):
        #if the target overshoots, then return nothing.
        if target < 0:
            return
        #if target is hit, then append the entire path, which has been passed/updated down each recursive call, to the result, then end the recursion
        if target == 0:
            result.append(path)
            return
        #this is the hard part
        for i in range(index, len(nums)):
            self.dfs(nums, target - nums[i], i, path + [num[i]], result)

'''
IMPORTANT / logic behind it:
These are all the paths taken. 2, 2, 2, 2 goes down index 0, 0, 0, 0, then returns cuz it failed, then goes 0, 0, 0, 1, etc. iterates over all the ones for 0, then after that returns it continues with the recursive sequence starting with 1. now we don't want 1, 0, 0, etc. because we already accounted for 0, 0, 0, 1 in the dfs before. this is why we only iterate starting with "index" for dfs calls.

not hit:
[2, 2, 2, 2]
not hit:
[2, 2, 2, 3]
not hit:
[2, 2, 2, 6]
not hit:
[2, 2, 2, 7]
hit:
[2, 2, 3]
not hit:
[2, 2, 6]
not hit:
[2, 2, 7]
hit:
[2, 3, 2]
not hit:
[2, 3, 3]
not hit:
[2, 3, 6]
not hit:
[2, 3, 7]
not hit:
[2, 6]
not hit:
[2, 7]
hit:
[3, 2, 2]
not hit:
[3, 2, 3]
not hit:
[3, 2, 6]
not hit:
[3, 2, 7]
not hit:
[3, 3, 2]
not hit:
[3, 3, 3]
not hit:
[3, 3, 6]
not hit:
[3, 3, 7]
not hit:
[3, 6]
not hit:
[3, 7]
not hit:
[6, 2]
not hit:
[6, 3]
not hit:
[6, 6]
not hit:
[6, 7]
hit:
[7]

'''
