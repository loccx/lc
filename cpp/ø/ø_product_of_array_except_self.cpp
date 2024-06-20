class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        res[0]=1;
        fork(1,n){
            res[k]=res[k-1]*nums[k-1];
        }
        int r=1;
        for(int k=n-1;k>=0;k--){
            res[k]*=r;
            r*=nums[k];
        }
        return res;
    }
};
