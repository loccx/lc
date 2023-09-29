class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        removed = 0

        intervals.sort(key = lambda x: x[1])

        prev = intervals[0][1]
        for index in range(1, len(intervals)):
            curr = intervals[index]
            if curr[0] < prev:
                removed += 1
            else:
                prev = curr[1]
        return removed
