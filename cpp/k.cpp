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
class NumberContainers {
public:
    NumberContainers() {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp; // num -> index
        unordered_map<int,int> indnum; // index -> num

    }
    
    void change(int index, int number) {
        if (!indnum.count(index)) {
            indnum[index] = number;
            mp[number].push(index);
        }
        else {
            mp[indnum[index]].erase(index);
            indnum[index]=number;
            mp[number].push(index);
        }
    }
    
    int find(int number) {
        if (mp.count(number) && mp[number].size()) {
            return mp[number].front();
        }
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
 
 
 
int main(){
    NumberContainers nc;
}
