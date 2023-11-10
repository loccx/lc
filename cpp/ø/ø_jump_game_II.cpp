#include <iostream>

using namespace std;

class Solution {
    public:

#ifdef DEBUG
        void printVec(vector<int>& vec) {
            for (auto v : vec) {
                cout << v << " ";
            }
            cout << '\n';
        }
#endif

        int jump(vector<int>& nums) {
            vector<int> jumps(nums.size(), INT_MAX);
            jumps[0] = 0;
            for (int x = 0; x < int(nums.size()); x++) {
                if (jumps[x] != INT_MAX) {
#ifdef DEBUG
                    cout << "nums[x]: " << nums[x] << '\n';
#endif
                    for (int k = 1; k <= nums[x]; k++) {
                        if (x+k < int(nums.size())) jumps[x+k] = min(jumps[x+k], jumps[x] + 1);
                        if (x-k >= 0) jumps[x-k] = min(jumps[x-k], jumps[x] + 1);
                        else continue;

                    }
#ifdef DEBUG
                    printVec(nums);
                    printVec(jumps);
#endif
                }
            }
            return jumps[int(jumps.size()) - 1];
        }
};

int main() {
    vector<int> inp = {2,3,1,1,4};
    Solution test;
    cout << test.jump(inp) << '\n';
}
