class Solution:
    def insejrt(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        
        # takes each interval in the intervals
        for interval in intervals:
            # if the current interval essentially doesn't overlap with the new interval at all, since it is completely less than it, then just add it to the result
            if interval[1] < newInterval[0]:
                result.append(interval)

            # we will only reach this conditional if the new interval's largest value has already been surpassed, so we can merge the new interval into the result now.
            # the interval is completely larger than the new interval, so we just add the new interval to the result and make the larger array the new interval to process
            elif interval[0] > newInterval[1]:
                result.append(newInterval)
                newInterval = interval
            # the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            # min and max functions allows us this to work for both lower and upper value overlaps
            elif interval[1] >= newInterval[0] or interval[0] <= newInterval[1]:
                newInterval[0] = min(interval[0], newInterval[0])
                newInterval[1] = max(newInterval[1], interval[1])
        
        result.append(newInterval); 
        return result
