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
class ll{
public:
    int val;
    ll* prev;
    ll* next;

    ll(){}
    ll(int k):val(k){}
};

class MyCircularDeque {
public:
    int currsize;
    int size;
    ll* head;
    ll* tail;
    MyCircularDeque(int k):size(k),currsize(0) {
    }
    
    bool insertFront(int value) {
        if(!currsize){
            head=new ll(value);
            tail=head;
            currsize++;
            return true;
        }
        else if(currsize==size)return false;
        else{
            ll* temp=head;
            head=new ll(value);
            temp->prev=head;;
            head->next=temp;
            currsize++;
            return true;
        }
    }
    
    bool insertLast(int value) {
        if(!currsize){
            head=new ll(value);
            tail=head;
            currsize++;
            return true;
        }
        else if(currsize==size)return false;
        else{
            ll* temp=tail;
            tail=new ll(value);
            temp->next=tail;
            tail->prev=temp;
            currsize++;
            return true;
        }
    }
    
    bool deleteFront() {
        if(!currsize){
            return false;
        }
        else if(currsize==1){
            delete head;
            head=nullptr;
            tail=nullptr;
            currsize=0;
            return true;
        }
        else{
            ll* temp=head;
            head=head->next;
            delete temp;
            temp=nullptr;
            head->prev=nullptr;
            currsize--;
            return true;
        }
    }
    
    bool deleteLast() {
        if(!currsize){
            return false;
        }
        else if(currsize==1){
            delete tail;
            tail=nullptr;
            head=nullptr;
            currsize=0;
            return true;
        }
        else{
            ll* temp=tail;
            tail=tail->prev;
            delete temp;
            temp=nullptr;
            tail->next=nullptr;
            currsize--;
            return true;
        }
    }
    
    int getFront() {
        if(!currsize)return -1;
        else return head->val;
    }
    
    int getRear() {
        if(!currsize)return -1;
        else return tail->val;
    }
    
    bool isEmpty() {
        return !currsize;
    }
    
    bool isFull() {
        return currsize==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
 
 
 
int main(){
    Solution s;
}
