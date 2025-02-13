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
vector<vector<char>> falling(vector<vector<char>> grid) {
    int m = grid.size();
    int n = grid[0].size();

    int min_d = INT_MAX;
    for (int c = 0; c < n; c++) {
        int it = 0;
        while (it < m) {
            int d = 0;
            while (it < m && grid[it][c] != 'F') {
                it++;
            }
            it++;
            while (it < m && grid[it][c] == '-') {
                d++;
                it++;
            }
            if (it < m && grid[it][c] == 'F') continue;
            else if (it < m && grid[it][c] == '#' && d < min_d) {
                min_d = d;
            }
            else if (it == m && d < min_d) {
                min_d = d;
            }
        }
    }
    for (int c = 0; c < n; c++) {
        for (int r = m-1; r >= 0; r--) {
            if (grid[r][c] == 'F') {
                grid[r + min_d][c] = 'F';
                grid[r][c] = '-';
            }
        }
    }

    return grid;
}

void pg(vector<vector<char>> gr) {
    for (auto& g : gr) {
        for (auto& c : g) {
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
 
int main() {
    vector<vector<char>> grid = {
        {'F', 'F', 'F', 'F', 'F'},
        {'-', '-', 'F', '-', '-'},
        {'-', '-', 'F', '-', '-'},
        {'-', 'F', 'F', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'}
    };

    pg(falling(grid));
}
