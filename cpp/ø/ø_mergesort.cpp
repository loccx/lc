#include<algorithm>
#include<iostream>
#include<cmath>
#include<set>
#include<queue>

#define endl '\n'
#define fork(a,b) for(ll k=a;k<b;k++)
#define fori(a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define fill(a,b,c) fill(a,a+b,c)
#define bug(x) cout<<#x<<" : "<<x<<'\n';
#define hi cout<<"hi\n";
#define inf INT_MAX

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef queue<int> qi;
typedef queue<pair<int,int>> qpi;

void pv(vi& v);

void mergesort(vi& v){
    if(int(v.size())==1)return;
    int m=int(v.size())/2;
    vi l,r;
    fork(0,m) l.push_back(v[k]);
    fori(m,v.size()) r.push_back(v[i]);
    mergesort(l);
    mergesort(r);
    int li=0,ri=0,k=0;
    while(li<l.size()&&ri<r.size()){
        if(l[li]<=r[ri]){
            v[k]=l[li];
            li++;
        }
        else{
            v[k]=r[ri];
            ri++;
        }
        k++;
    }
    while(li<l.size()){
        v[k]=l[li];
        li++;
        k++;
    }
    while(li<l.size()){
        v[k]=r[ri];
        ri++;
        k++;
    }
}

void pv(vi& v){
    for(int c:v){
        cout<<c<<" ";
    }
    cout<<endl;
}

void solve(){
    vi v;
    int n;
    while(cin>>n){
        v.push_back(n);
    }
    cout<<"unsorted:\n";
    pv(v);

    mergesort(v);

    cout<<"sorted:\n";
    pv(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}
