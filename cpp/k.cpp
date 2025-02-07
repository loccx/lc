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
class LRUCache {
public:
    queue<int> qu;
    int cap, currsize;
    vector<int> map;
    vector<int> freq;

    LRUCache(int cap) {
        currsize = 0;
        capacity = cap;
        map.resize(10001, -1);
        freq.resize(10001, -1);
    }
    
    int get(int key) {
        if (map[key] == -1) {
            return -1;
        }

        qu.push(key);
        freq[key]++;
        return map[key];
    }
    
    void put(int key, int value) {
        if (map[key] == -1) { // key doesnt exist
            while (currsize >= capacity) { // remove least recently used key
                int fr = qu.front();
                qu.pop();

                if (freq[fr] == 1) {
                    map[fr] = -1;
                    currsize--;
                }

                freq[fr]--;
            }

            qu.push(key);
            map[key] = value;
            freq[key] = 1;

            currsize++;
        }
        else {
            qu.push(key);
            map[key] = value;
            freq[key]++;
        }
    }
};
 
 
 
int main(){
    Solution s;
}
