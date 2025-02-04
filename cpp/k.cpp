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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        for (auto& flower : flowers) {
            mp[flower[0]]++;
            mp[flower[1]+1]--;
        }

        sort(people.begin(), people.end());

        int n = flowers.size();
        int it = 0;
        int count = 0;
        vector<int> res;

        unordered_map<int,int> counter;

        for (auto& p : mp) {
            while (it < people.size() && people[it] < p.first) {
                counter[people[it]] = count;
                it++;
            }
            count += p.second;
        }

        int last = counter.rbegin()->first;
        for (int k = 0; k < people.size(); k++) {
            if (people[k] > last) res.push_back(0);
            else res.push_back(counter[people[k]]);
        }

        return res;
    }
}; 
 
 
int main(){
    Solution s;
}
