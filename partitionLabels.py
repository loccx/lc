class Solution:
    def partitionLabels(s: str):
        lastInd = {}
        for n in range(len(s)):
            lastInd[s[n]] = n
        
        collector = []
        count = 0
        longest = 0

        for n in range(len(s)):
            count += 1
            if lastInd[s[n]] > longest:
                longest = lastInd[s[n]]
            if s[n] == s[longest]:
                collector.append(count)
                count = 0
                longest = 0
        return collector

test = Solution
test.partitionLabels("ababcbacadefegdehijhklij")