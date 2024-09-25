#include<bits/stdc++.h>
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
//#define f first
//#define s second
 
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
//solution class
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        unordered_set<string> pref;
        for(int& a:arr1){
            string curr=to_string(a);
            for(int k=1;k<=curr.size();k++){
                pref.insert(curr.substr(0,k));
            }
        }

        int res=0;
        for(int& b:arr2){
            string curr=to_string(b);
            for(int k=curr.size();k>0;k--){
                if(pref.count(curr.substr(0,k)))res=max(res,int(curr.substr(0,k).size()));
            }
        }
        return res;
    }
};
 
 
 
int main(){
    vector<int> a1={1, 10, 100};
    vector<int> a2={1000};
    Solution s;
    cout<<s.longestCommonPrefix(a1,a2)<<endl;
    return 0;
}
