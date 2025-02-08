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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int& n = numCourses;
        vector<vector<int>> adj(n,vector<int>());
        vector<int> deg(n,0);
        vector<int> vis(n,false);
        for (auto& pre : prerequisites) {
            if (pre[1] == pre[0]) return false;
            adj[pre[1]].push_back(pre[0]);
            deg[pre[0]]++;
        }
        stack<int> s;

        for (int k = 0; k < n; k++) {
            if (deg[k] == 0) {
                s.push(k);
            }
        }
        if (s.empty()) return false; // no deg 0 courses

        int viscount = 0;
        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            if (!vis[curr]) {
                vis[curr] = true;
                viscount++;
                for (int& nei : adj[curr]) {
                    if (--deg[nei] == 0)s.push(nei);
                }
            }
            else return false;
        }
        return viscount == n;
    }
};
 
 
 
int main(){
    Solution s;
}
