#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<numeric>

using namespace std;

#define endl '\n'
#define fork(a,b) for(ll k=a;k<b;k++)
#define fori(a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define fill(a,b,c) fill(a,a+b,c)
#define bug(x) cout<<#x<<" : "<<x<<'\n';
#define hi cout<<"hi\n";
#define inf 1<<28
#define pb push_back
#define PI M_PI
#define PI2 M_PI_2
#define c(k) int k;cin>>k;
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<pd> vpd;
typedef vector<pll> vpll;
typedef queue<int> qi;
typedef queue<pair<int,int>> qpi;

const static auto fast=[]{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

//Solution class goes here

class Solution {
public:
    map<string,int> m;
    string countOfAtoms(string formula) {
        int n=formula.length;
        map<string,int> mp;
        stack<unordered_map<string,int> sm;
        sm.push({});

        int k=0;
        while(k<n){
            if(formula[k]=='('){
                sm.push({});
                k++;
            }
            else if(formula[k]==')'){
                auto popped=sm.top();
                sm.pop();
                k++;
                int begin=k;
                while(k<n && isdigit(formula[k]))k++;
                int mult = k>begin && isdigit(formula[begin]) ? stoi(formula.substr(begin,k-begin)) : 1;
                for(auto p:popped){
                    sm.top()[p.first]+=mult*p.second;
                }
            }
            else{
                int begin=k;
                k++;
                while(k<n && islower(formula[k]))k++;
                string elem=formula.substr(begin,k-begin);

                begin=k;
                while(k<n && isdigit(formula[k]))k++;
                int mult = k>begin && isdigit(formula[begin]) ? stoi(formula.substr(begin,k-begin)) : 1;
                sm.top()[elem]+=mult;
            }
        }

        string res="";
        for(auto pair:sm.top()){
            res+=(pair.first+pair.second);
        }
        return res;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution s;
    cout<< s <<endl;
    return 0;
}
