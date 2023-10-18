class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        
        vector<int> res;
        for (int x = 0; x < k; x++) {
            res.push_back(nums.front());
            pop_head(nums.begin(), nums.end());
        }

        for (auto r : res) {
            cout << r << " ";
        }
        cout << '\n';
    }
};
