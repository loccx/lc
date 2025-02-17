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
    int numTilePossibilities(string tiles) {
        int res = 0;
        int n = tiles.size();
        unordered_map<char, int> count;
        for (int k = 0; k < n; k++) {
            count[tiles[k]]++;
        }

        bt(count, res, 0, n);
        return res - 1;
    }

    void bt(unordered_map<char, int>& count, int& res, int k, int n) {
        res++;
        if (k == n) return;
        for (auto& p : count) {
            if (p.second > 0) {
                count[p.first]--;
                bt(count, res, k + 1, n);
                count[p.first]++;
            }
        }
    }
};
 
 
 
int main(){
    Solution s;
}
