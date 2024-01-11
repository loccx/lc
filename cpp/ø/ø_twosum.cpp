#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

/*
class Solution {
    public:
        vector<pair<int, int>> twosum(vector<int>& n, int target) {
            vector<pair<int, int>> res;
            unordered_map<int, int> m;

            for (int k = 0; k < int(n.size()); k++) {
                if (m.find(target - n[k]) != m.end()) {
                    res.push_back({m[target - n[k]], k});
                }
                else {
                    m[n[k]] = k;
                }
            }

            return res;
        }
};

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
*/

int main() {
    Solution test;
    vector<int> inp = {1, 2, 3, 4, 5, 6, 7};
    vector<pair<int, int>> res = test.twosum(inp, 8);

    for (auto k : res) {
        cout << "(" << k.first << ", " << k.second << ")" << " ";
    }
    cout << '\n';
}
