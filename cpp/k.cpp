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

void pvv(vector<vector<int>>& gr){
    for(auto& g:gr){
        for(int n:g){
            cout<<n<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

const static auto fast=[]{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
//solution class
class Solution {
public:
    void rec(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& deg,vector<vector<bool>>& vis){
        if(deg[r][c]&&!vis[r][c]){
            vis[r][c]=true;
            int n=grid.size();
            int m=grid[0].size();
            if(r>0&&grid[r-1][c]==1&&!vis[r-1][c]){
                deg[r-1][c]++;
                rec(grid,r-1,c,deg,vis);
            }
            if(r<n-1&&grid[r+1][c]==1&&!vis[r+1][c]){
                deg[r+1][c]++;
                rec(grid,r+1,c,deg,vis);
            }
            if(c>0&&grid[r][c-1]==1&&!vis[r][c-1]){
                deg[r][c-1]++;
                rec(grid,r,c-1,deg,vis);
            }
            if(c<m-1&&grid[r][c+1]==1&&!vis[r][c+1]){
                deg[r][c+1]++;
                rec(grid,r,c+1,deg,vis);
            }
        }
    }

    void destroy(vector<vector<int>>& grid,vector<vector<int>>& deg,vector<vector<bool>>& vis,int r,int c,int& count){
        if(!vis[r][c]){
            vis[r][c]=true;
            int n=grid.size();
            int m=grid[0].size();

            if(r>0&&deg[r-1][c]>0&&!vis[r-1][c]){
                deg[r-1][c]--;
                if(deg[r-1][c]==0){
                    count++;
                    grid[r-1][c]=0;
                }
                rec(grid,r-1,c,deg,vis);
            }
            if(r<n-1&&deg[r+1][c]>0&&!vis[r+1][c]){
                deg[r+1][c]--;
                if(deg[r+1][c]==0){
                    count++;
                    grid[r+1][c]=0;
                }
                rec(grid,r+1,c,deg,vis);
            }
            if(c>0&&deg[r][c-1]>0&&!vis[r][c-1]){
                deg[r][c-1]--;
                if(deg[r][c-1]==0){
                    count++;
                    grid[r][c-1]=0;
                }
                rec(grid,r,c-1,deg,vis);
            }
            if(c<m-1&&deg[r][c+1]>0&&!vis[r][c+1]){
                deg[r][c+1]--;
                if(deg[r][c+1]==0){
                    count++;
                    grid[r][c+1]=0;
                }
                rec(grid,r,c+1,deg,vis);
            }
        }
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> deg(n,vector<int>(m,0));
        for(int x=0;x<m;x++){
            if(grid[0][x]==1){
                deg[0][x]++;
                rec(grid,0,x,deg,vis);
                vis.assign(n,vector<bool>(m,false));
            }
        }

        pvv(deg);

        vis.assign(n,vector<bool>(m,false));
        vector<int> res;
        for(auto& hit:hits){
            int curr=0;
            if(deg[hit[0]][hit[1]]>0){
                deg[hit[0]][hit[1]]=0;
                destroy(grid,deg,vis,hit[0],hit[1],curr);
                res.push_back(curr);
                vis.assign(n,vector<bool>(m,false));
            }
            else res.push_back(0);
        }
        return res;
    }
};
 
void pv(vector<int>& vec){
    for(int v:vec){
        cout<<v<<' ';
    }
    cout<<endl;
}
 
 
int main(){
    vector<vector<int>> inp={{1,0,0,0},{1,1,0,0}};
    vector<vector<int>> hit={{1,1},{1,0}};
    Solution s;
    vector<int> res=s.hitBricks(inp,hit);
    pv(res);
}
