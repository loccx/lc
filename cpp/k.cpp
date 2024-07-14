#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<queue>
#include<numeric>

using namespace std;

#define endl '\n'
#define fork(a,b) for(ll k=a;k<b;k++)
#define fori(a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define fill(a,b,c) fill(a,a+b,c)
#define bug(x) cout<<#x<<" : "<<x<<'\n';
#define hi cout<<"hi\n";
#define inf 1<<28
#define pb push_back
#define PI M_PI
#define PI2 M_PI_2
#define c(k) int k;cin>>k;
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<pd> vpd;
typedef vector<pll> vpll;
typedef queue<int> qi;
typedef queue<pair<int,int>> qpi;

const static auto fast=[]{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

//Solution class goes here

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<long long,int> l,r;
        int n=nums.size();
        long long s=accumulate(nums.begin(),nums.end(),0L);
        long long left=0,right;
        for(int x=0;x<n-1;x++){
            left+=nums[x];
            right=s-left;
            r[right-left]++;
        }

        int res=r[0];
        left=0;
        for(int x=0;x<n;x++){
            left+=nums[x];
            right=s-left;
            int diff=k-nums[x];
            res=max(res,l[-diff]+r[diff]);
            l[right-left]++;
            r[right-left]--;
        }
        return res;
    }
};




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution s;
    cout<< s <<endl;
    return 0;
}
