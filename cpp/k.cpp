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
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();

        string res = "";

        int it = n-1;
        int it2 = m-1;
        bool carry = false;
        while (it>=0 && it2>=0) {
            if (carry) {
                if (a[it] == '0' && b[it2] == '0') {
                    res = '1' + res;
                    carry ^= 1;
                }
                else if ((a[it] == '0' && b[it2] == '1') || (a[it] == '1' && b[it2] == '0')) {
                    res = '0' + res;
                }
                else if (a[it] == '1' && b[it2] == '1') {
                    res = '1' + res;
                }
            }
            else { // no carry
                if (a[it] == '0' && b[it2] == '0') {
                    res = '0' + res;
                }
                else if ((a[it] == '0' && b[it2] == '1') || (a[it] == '1' && b[it2] == '0')) {
                    res = '1' + res;
                }
                else if (a[it] == '1' && b[it2] == '1') {
                    res = '0' + res;
                    carry ^= 1;
                }
            }
        }
        while (it >= 0) {
            if (carry) {
                if (a[it] == '0') {
                    res = '1' + res;
                    carry ^= 1;
                }
                else {
                    res = '0' + res;
                    carry ^= 1;
                }
            }
            else res = a[it] + res;
        }
        while (it2 >= 0) {
            if (carry) {
                if (b[it2] == '0') {
                    res = '1' + res;
                    carry ^= 1;
                }
                else {
                    res = '0' + res;
                    carry ^= 1;
                }
            }
            else res = b[it2] + res;
        }
        return res;
    }
};
 
 
 
int main(){
    Solution s;
}
