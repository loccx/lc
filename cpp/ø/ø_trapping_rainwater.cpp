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
    int trap(vector<int>& height) {
        int p=0,p2=height.size()-1;
        int ml=0,mr=0;
        int res=0;
        while(p<p2){
            if(height[p]<height[p2]){
                if(height[p]>ml)ml=height[p];
                else{
                    res+=ml-height[p];
                    p++;
                }
            }
            else{
                if(height[p2]>mr)mr=height[p2];
                else{
                    res+=mr-height[p2];
                    p2--;
                }
            }
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
