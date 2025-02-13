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
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> a(n + m, 0);

        for (int k = n-1; k >= 0; k--) {
            for (int x = m-1; x >= 0; x--) {
                int sum = (num1[k] - '0') * (num2[x] - '0') + a[k + x + 1];
                a[k + x + 1] = sum % 10;
                a[k + x] += sum / 10;
            }
        }

        string res = "";
        bool skip = true;
        for (int k = 0; k < n + m; k++) {
            cout << a[k] << ' ';
            if (a[k] == 0 && skip) continue;
            skip = false;
            res += a[k] + '0';
        }
        cout << endl;
        return res;
    }
};
 
 
 
int main(){
    string num1 = "123";
    string num2 = "456";
    Solution s;
    cout << s.multiply(num1, num2) << endl;
}
