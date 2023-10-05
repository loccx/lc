class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        counter = {}
        answer = []

        for x in nums:
            if x not in counter:
                counter[x] = 0
            counter[x]+=1
        sorted_counter = dict(sorted(counter.items()), key = lambda x: x[1], reverse = True))

        return list(sorted_counter.keys())[:k]
