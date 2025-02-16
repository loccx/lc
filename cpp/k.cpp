#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fork(a,b) for(ll k=a;k<b;k++)
#define forx(a,b) for(ll x=a;x<b;x++)
#define mem(a,b) memset(a,b,sizeof(a))
#define fill(a,b,v) fill(a,a+b,v)
#define mp(a,b) make_pair(a,b)
#define bug(x) cout<<#x<<" : "<<x<<'\n';
#define pb push_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define sz(x) int(x.size())
 
using ll = long long;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<ll,ll> pll;
template<class t> using V=vector<t>;
template<class t> using VV=V<V<t>>;
template<class t> using Q=queue<t>;
template<class t1,class t2> using MP=unordered_map<t1,t2>;
typedef priority_queue<int> pqi;
 
const ll M=1e9+7;
const ll N=2*1e5+10;

const static auto fast=[]{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
//solution class
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> vis(n + 1, false);
        bt(res, vis, n, 0);
        return res;
    }

    bool bt(vector<int>& res, vector<bool>& vis, int n, int ind) {
        while (ind < res.size() && res[ind] != 0) ind++;
        if (ind == res.size()) {
            return true;
        }

        for (int k = n; k >= 1; k--) {
            if (vis[k]) continue;

            if (ind < res.size() && k == 1) {
                res[ind] = 1;
                vis[1] = true;
                if (bt(res, vis, n, ind + 1)) return true;
                res[ind] = 0;
                vis[1] = false;
            }
            else if (ind + k <= res.size() - 1 && res[ind + k] == 0) {
                res[ind] = k;
                res[ind + k] = k;
                vis[k] = true;
                if (bt(res, vis, n, ind + 1)) return true;
                res[ind] = 0;
                res[ind + k] = 0;
                vis[k] = false;
            }
        }
        return false;
    }
};
 
 
 
int main(){
    Solution s;
}
