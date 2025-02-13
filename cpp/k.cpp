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
        string res;
        vector<string> nums;
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() < num2.size())
            swap(num1, num2);

        int n = num1.size();
        int m = num2.size();

        int bigsum = 0;
        int mult = 0;
        for (int x = m-1; x >= 0; x--) {
            int carry = 0;
            string sum = "";
            for (int k = n-1; k >= 0; k--) {
                int top = num1[k] - '0';
                int bot = num2[x] - '0';

                int prod = top * bot + carry;

                if (prod > 9) carry = prod / 10;
                else carry = 0;
                char dig = (prod % 10) + '0';
                sum.insert(0, 1, dig);
            }
            if (carry)
                sum.insert(0, 1, (carry + '0'));
            for (int m = 0; m < mult; m++) sum += '0';
            mult++;
            nums.push_back(sum);
        }
        int f = nums.size();
        if (f == 1) return nums[0];

        string curr = nums[0];

        for (int k = 1; k < f; k++) {
            if (curr.size() < nums[k].size()) swap(curr, nums[k]);
            int carry = 0;
            int ci = curr.size() - 1;
            int ni = nums[k].size() - 1;
            while (ni >= 0) {
                int sum = (nums[k][ni] - '0') + (curr[ci] - '0') + carry;
                carry = sum / 10;
                curr[ci] = (sum % 10) + '0';
                ni--;
                ci--;
            }
            while (carry && ci >= 0) {
                int sum = (curr[ci] - '0') + carry;
                carry = sum / 10;
                curr[ci] = (sum % 10) + '0';
                ci--;
            }
            if (carry) curr.insert(0, 1, '1');
        }

        return curr;
    }
};
 
 
 
int main(){
    string num1 = "123";
    string num2 = "4567";
    Solution s;
    s.multiply(num1, num2);
}
