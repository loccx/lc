#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (int(nums.size()) < 2) return int(nums.size());

        sort(nums.begin(), nums.end());

        int res = 1;
        int currRes = 1;
        for (int k = 1; k < int(nums.size()); k++) {
            if (nums[k] == nums[k-1] + 1) {
                currRes++;
            }
            else if (nums[k] == nums[k-1]) continue;
            else {
                res = max(currRes, res);
                currRes = 1;
            }
        }
        res = max(currRes, res);

        return res;
    }
};

int main() {
    vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    Solution s;
    cout << "longest consecutive subsequence: " << s.longestConsecutive(input) << '\n';
    return 0;
}
