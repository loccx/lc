#include <iostream>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int k = 0; k < nums.size(); k++) {
            if (m[target - nums[k]]) return {m[target - nums[k]], k};
            else m[nums[k]] = k;
        }
        return {};
    }
};
