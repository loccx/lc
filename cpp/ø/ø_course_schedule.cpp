#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

#define endl '\n'
#define fork(a,b) for(ll k=a;k<b;k++)
#define fori(a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define fill(a,b,c) fill(a,a+b,c)
#define bug(x) cout<<#x<<" : "<<x<<'\n';
#define hi cout<<"hi\n";
#define inf INT_MAX
#define pb push_back
#define PI M_PI
#define PI2 M_PI_2
#define c(k) int k;cin>>k;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<pi> vpi;
typedef vector<pd> vpd;
typedef vector<pll> vpll;
typedef queue<int> qi;
typedef queue<pair<int,int>> qpi;

/*
There are a total of `n` courses you have to take, labeled from `0` to `n
- 1`. Some courses may have prerequisites, for example to take course `i`,
you have to first take all the courses it's prerequisite.
 
Given the `n` and an array `prerequisites` where `prerequisites[i]`
contains the pair `(ai, bi)` indicating that you must take course `bi`
before course `ai`.
 
Return if you can finish all courses. If yes, return true, else return
false.
*/

bool has_cycle(int k, vector<vector<int>>& prereq) {
    vector<bool> visited(false, int(prereq.size()));
    stack<int> s;
    s.push(prereq(k));
    visited[k] = true;

    while (!stack.empty()) {
        int curr = s.top();
        s.pop();

        for (auto p : prereq[curr]) {
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }
            else return true;
        }
    }

    return false;
}

bool courses_possible(vector<vector<int>>& prereq) {
    for (int k = 0; k < int(prereq.size()); k++) {
        if (dfs(k, prereq)) return false;
    }
    return true;
}

bool canfinish(vvi& prerequisites){

}

int main() {
    int n;
    cout << "How many courses do you have to take?\n";
    cin >> n;

    vector<vector<int>> prerequisites = {};

    bool res = courses_possible(prerequisites);

    if (res) cout << "Possible!\n";
    else cout << "Not Possible.\n";

    return 0;
}
