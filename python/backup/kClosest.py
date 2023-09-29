import heapq

class Solution:
    def kClosest(points, k):
        distances = []
        closest = []
        index = 0
        for x,y in k:
            distances.append([(x*x+y*y)**0.5, index]) #adds all the distances into one list, in order of the coordinates
            index += 1
        distances.sort()
        for n in k:
            closest.append(distances[n][1])
        return closest
