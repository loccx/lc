class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []

        maximums = deque()

        left, right = 0, k - 1
        for index in range(len(nums)):
