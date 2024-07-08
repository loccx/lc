#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<queue>
#include<unordered_set>
#include<unordered_map>
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
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int> lscores(n,0),rscores(n,0);
        int lmax=0,rmin=INT_MAX;
        for(int k=1,x=n-2;k<n-1&&x>=1;k++,x--){
            if(nums[k]>nums[k-1]){
                if(nums[k]>lmax){
                    lscores[k]=2;
                    lmax=nums[k];
                }
                else lscores[k]=1;
            }
            if(nums[x]<nums[x+1]){
                if(nums[x]<rmin){
                    rscores[x]=2;
                    rmin=nums[x];
                }
                else rscores[x]=1;
            }
        }
        int score=0;
        for(int k=1;k<n-1;k++){
            score+=min(lscores[k],rscores[k]);
        }
        return score;
    }
};





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<int> inp={2,4,6,4};
    Solution s;
    cout<<s.sumOfBeauties(inp)<<endl;
    return 0;
}
