#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
#include<map>

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
typedef unordered_map<int,int> umii;
typedef unordered_map<string,int> umsi;
typedef unordered_map<int,string> umis;

//Solution class goes here
class lru {
public:
    int size;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    lru(int size):size(size){}

    int get(int key){
        if(mp.find(key)==mp.end())return -1;
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;
    }

    void put(int key,int val){
        if(mp.find(key)!=mp.end()){
            l.splice(l.begin(),l,mp[key]);
            mp[key]->second=val;
            return;
        }
        if(l.size()==size){
            auto d=l.back();
            l.pop_back();
            mp.erase(d.first);
        }
        l.push_front({key,val});
        mp[key]=l.begin();
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    lru l(2);
    l.put(1,1);
    l.put(2,2);
    cout<<l.get(1)<<endl;
    l.put(3,3);
    cout<<l.get(2)<<endl;
    l.put(4,4);
    cout<<l.get(1)<<endl;
    cout<<l.get(2)<<endl;
    cout<<l.get(3)<<endl;
    cout<<l.get(4)<<endl;
    return 0;
}
