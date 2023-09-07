/* Given an integer array nums, return the length of the longest strictly increasing subsequence */

class Solution {
public:
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
};
