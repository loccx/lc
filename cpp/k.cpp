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
//solution
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="")return 0;
        int n=s.size();
        int res=0;
        stack<int> mem;
        mem.push(-1);
        for(int k=0;k<n;k++){
            if(s[k]=='('){
                mem.push(k);
            }
            else{
                if(!mem.empty())mem.pop();
                if(mem.empty()){
                    mem.push(k);
                }
                else{
                    res=max(res,k-mem.top());
                }
            }
        }
        return res;
    }
};





int main(){
    Solution s;
    cout<<s.longestValidParentheses("()(()")<<endl;
}
