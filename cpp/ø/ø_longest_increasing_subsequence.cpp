/* Given an integer array nums, return the length of the longest strictly increasing subsequence */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int k = 0; k < n; k++) {
            for (int x = 0; x < k; x++) {
                if (nums[k] > nums[x] && dp[k] < dp[x] + 1) {
                    dp[k] = dp[x] + 1;
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

    /*
    int lengthOfLIS(vector<int>& nums) {
        // n is length of the array
        int n = nums.size();

        // initialize dp array with all 1's, of the same length
        vector<int> dp(n, 1);

        // outer loop for each num in nums
        for (int i = 0; i < n; ++i)
            // inner loop for each num before the current outer num
            for (int j = 0; j < i; ++j)

                // if outer num > inner num and the dp streak for the outer num is < the inner num streak + 1, update it to be the incremented inner loop streak
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        // the maximum streak in the dp array is the longest increasing subsequence
        return *max_element(dp.begin(), dp.end());
    }
    */
};

int main() {
    Solution s;
    vector<int> inp = {6, 2, 4, 4, 8, 4, 3, 1, 45, 6, 3, 4};
    cout << s.lengthOfLIS(inp) << '\n';
    return 0;
}
