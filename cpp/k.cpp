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
class LRU () {
public:
    int capacity;
    int currsize;
    queue<int> qu;
    vector<int> freq;
    vector<int> map;

    LRU (int cap) : capacity(cap), currsize(0) {
        map.resize(1e4+1,-1);
        freq.resize(1e4+1,-1);
    }

    int get(int key) {
        if (map[key] == -1) return -1;

        qu.push(key);
        freq[key]++;
        return map[key];
    }

    int put(int key, int value) {
        if (map[key] == -1) {
            while (currsize >= capacity) {
                int fr = qu.front();
                qu.pop();
                if (freq[fr] == 1) {
                    currsize--;
                    map[fr] = -1;
                }
                freq[fr]--;
                map[key] = value;
                qu.push(key);
                freq[key]=1;
                currsize++;
            }
        }
        else {
            map[key] = value;
            qu.push(key);
            freq[key]++;
        }
    }
}
 
 
 
int main(){
    Solution s;
}
