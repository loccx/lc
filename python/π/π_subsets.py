class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for n in nums:
            subsets = []
            for y in result:
                subset = y + [n]
                subsets.append(subset)
            result.extend(subsets)
        return result
