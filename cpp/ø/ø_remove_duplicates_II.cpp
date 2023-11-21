#include <iostream>

using namespace std;

class Solution {
    public:
        void printVec(vector<int>& vec) {
            for (auto v : vec) {
                cout << v << " ";
            }
            cout << '\n';
        }

        int removeDuplicates(vector<int>& nums) {
            int i = 0;
            for (auto n : nums) {
                if (i == 0 || i == 1 || nums[i-2] != n) {
                    nums[i] = n;
                    i++;
                }
            }
            printVec(nums);
            return i;
        }
};

int main() {
    vector<int> inp = {0,0,1,1,1,1,2,3,3};

    Solution s;
    int ans = s.removeDuplicates(inp);
    cout << ans << '\n';
    return 0;
}
