#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<queue>

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

//Solution class goes here
class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[k+1][n+1];

        for(int i=0;i<n+1;i++)dp[1][i]=i;
        for(int i=1;i<k+1;i++){
            dp[i][0]=0;
            dp[i][1]=1;
        }

        for(int egg=2;egg<=k;egg++){
            for(int fl=2;fl<=n;fl++){
                int res=INT_MAX,l=1,h=fl;
                while(l<=h){
                    int mid = (l+h)/2;
                    int br=dp[egg-1][mid-1];
                    int nbr=dp[egg][fl-mid];
                    res=min(res,1+max(br,nbr));
                    if(br<nbr)l=mid+1;
                    else h=mid-1;
                }
                dp[egg][fl]=res;
            }
        }
        return dp[k][n];
    }
};




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution s;
    cout<< s.superEggDrop(2,100) <<endl;
    return 0;
}
