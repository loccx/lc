class Solution(object):
    def numRescueBoats(self, people, limit):
        # sort the people list by weight
        people.sort()

        # initialize left and right pointers on the very left and right
        i, j = 0, len(people) - 1

        # set answer to 0
        ans = 0
        # while the left pointer is less than the right pointer
        while i <= j:
            # answer increments
            # answer will always increment because as long as the pointers do not converge, there are more boats needed.
            # the only condition that lessens the # of boats required is when the left pointer increments
            ans += 1
            # if the people on the left and right sides weight can fit in one boat
            if people[i] + people[j] <= limit:
                # increase the weight of the first person by incrementing
                i += 1
            # if it's over the weight limit, lower the weight of the second person by decrementing
            j -= 1
        # when the weight can't move anywhere, when the pointers combine, return the number of boats required
        return ans
