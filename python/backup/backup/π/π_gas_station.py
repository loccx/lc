class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start = 0
        totalGas = 0
        totalCost = 0
        currGas = 0
        for k in range(len(gas)):
            totalGas += gas[k]
            totalCost += cost[k]
            currGas += gas[k] - cost[k]
            if currGas < 0:
                start = k + 1
                currGas = 0
        return totalGas < totalCost ? -1 : start
