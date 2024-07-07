class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res=0;
        int sum=0;
        m[sum]=1;
        for(int n:nums){
            sum+=n;
            if(m.find(sum-k)!=m.end()){
                res+=m[sum-k];
            }
            m[sum]++;
        }
        return res;
    }
};

