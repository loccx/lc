class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        #Counter(s1) stores the count of each letter in s1 in a hashmap
        #length represents the length of the desired substring
        #matched will indicate the number of matched letter counts between substring and s2
        counter, length, matched = Counter(s1), len(s1), 0   

        # x iterates across all the indexes in s2 string
        for x in range(len(s2)):

            # s2[x] is the current letter
            # if current letter is in s1 counter, then decrement the counter in s1 by 1.
            if s2[x] in counter:
                counter[s2[x]] -= 1
                # if after decrementing it the count of that letter goes to 0, then increase the # of matches by 1.
                if counter[s2[x]] == 0:
                    matched += 1

            # this starts counting only after x iterates past the length of the substring and now we start removing letters as x goes on, to maintain the length of the substring
            if x >= length and s2[x - length] in counter:
                # as x goes on and one of the counters is 0 already as we leave the letter behind, then the # of matches goes down.
                if counter[x - length] == 0:
                    matched -= 1
                # since we left it, the counter in s1 increments again.
                counter[s2[x - length]] += 1

            # if the # of matched letters is the same as the length of substring s1, then we know we have a match
            # the reason this algorithn works is because we are dealing with permutations of the substring, not the substring itself, so it is not the order of the letters that matters but simply the # of times it appears in the substring.
            if matched == len(counter):
                return True

        # if after iterating through the whole string we haven't found a match, then clearly there is no viable permutation.
        return False
