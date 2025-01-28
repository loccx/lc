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
    int longestCycle(vector<int>& edges) {
        int n=edges.size();

        vector<bool> vi(n,false);
        vector<int> bt(n,-1);

        int res=-1;
        stack<int> s;

        for(int k=0;k<n;k++){
            if(!vi[k]&&edges[k]!=-1){
                s.push(k);
                while(!s.empty()){
                    int c=s.top();
                    s.pop();
                    vi[c]=true;
                    if(edges[c]!=-1){
                        bt[edges[c]]=c;
                        if(vi[edges[c]]){
                            int o=edges[c];
                            int cl=1;
                            while(c!=o){
                                c=bt[c];
                                cl++;
                            }
                            if(cl!=-1)res=max(res,cl);
                        }
                        else{
                            s.push(edges[c]);
                        }
                    }
                }
            }
        }
        return res;
    }
}; 

 
 
 
int main(){
    V<int> inp={1,0};
    V<int> inp2={-1,4,-1,2,0,4};
    Solution s;
    cout<<s.longestCycle(inp2)<<endl;
}
