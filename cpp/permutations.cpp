#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void printVec(vector<int> &nums) {
        for (auto n : nums) {
            cout << n << " ";
        }
        cout << '\n';
    }
    
    void permutation(vector<int> &nums,int i,int n){
#ifdef DEBUG
        cout << '\n';
        printVec(nums);
        cout << i << " " << n << '\n';
#endif
        if(i==n){
            result.push_back(nums);
            printVec(result);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap(nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums,0,nums.size()-1);
        return result;
    }
};

int main() {
    vector<int> input = {1, 2, 3};
    Solution test;
    vector<vector<int>> sol = test.permute(input);

    cout << "[";
    for (int k = 0; k < int(sol.size()); k++) {
        cout << "(";
        for (int x = 0; x < int(sol[k].size()); x++) {
            cout << sol[k][x];
            if (x != int(sol[k].size() - 1)) cout << ", ";
        }
        cout << ")";
        if (k != int(sol.size()) - 1) cout << ", ";
    }
    cout << "]";
    cout << '\n';
}
