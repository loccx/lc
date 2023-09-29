class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, currGas = 0, totalGas = 0, totalCost = 0;

        for (int k = 0; k < gas.size(); k++) {
            totalGas += gas[k];
            totalCost += cost[k];

            currGas += gas[k] - cost[k];
            if (currGas < 0) {
                start = k+1;
                currGas = 0;
            }
        }

        return (totalGas < totalCost ) ? -1 : start;
    }
};
