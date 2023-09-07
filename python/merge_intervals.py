def merge(self, intervals: 'List[Interval]') -> 'List[Interval]':
	if not intervals:
        return []

	intervals.sort()

	unique = []

    # last stores the previous interval
	last = intervals[0]
	for cur in intervals:
        # if the current initial value is <= to the previous terminal value, then merge them
		if cur[0] <= last[1]:
			last[1] = max(last[1], cur[1])
		else:
            # otherwise, just append the last one, and make the last one the current one before moving on
			unique.append(last)
			last = cur

    # this is just to append the very last interval, since in the final iteration, last is set to curr, the last interval in the intervals, but isn't appended
	unique.append(last)
	return unique
