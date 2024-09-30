#include<bits/stdc++.h>
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
//#define f first
//#define s second
 
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
//solution class
#include <iostream>

class ll {
public:
    int val;
    ll* prev;
    ll* next;

    ll():val(0),prev(nullptr),next(nullptr){}
    ll(int k):val(k),prev(nullptr),next(nullptr){}
};

class CustomStack {
private:
    int currsize;
    int max;
    ll* head;
    ll* tail;

public:
    CustomStack(int maxSize) : currsize(0), max(maxSize), head(nullptr), tail(nullptr) {}
    
    void push(int x) {
        if(currsize==0){
            head=new ll(x);
            tail=head;
            currsize++;
        }
        else if(currsize<max){
            tail->next=new ll(x);
            tail->next->prev = tail;
            tail=tail->next;
            currsize++;
        }
    }
    
    int pop() {
        if(currsize==0)return -1;
        int store=tail->val;
        ll* temp=tail;
        if(currsize==1){
            head=tail=nullptr;
        }
        else{
            tail=tail->prev;
            tail->next=nullptr;
        }
        delete temp;
        temp=nullptr;
        currsize--;
        return store;
    }
    
    void increment(int k, int val) {
        ll* curr=head;
        while(k--&&curr!=nullptr){
            curr->val+=val;
            curr=curr->next;
        }
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
 
 
 
int main(){
    Solution s;
}
