#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int check[100000] = {-1};
        int size = nums.size();
        for(int k=0;k<size;k++){
            if(nums[k]<100000)check[nums[k]-1]=1;
        }
        for(int k=0;k<100000;k++){
            if(check[k]==-1)return k+1;
        }
        return 100001;
    }
};

int main(){
    vector<int> inp = {3,4,-1,1};
    Solution s;
    cout<<s.firstMissingPositive(inp)<<'\n';
}
