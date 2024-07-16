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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    string start="";
    string dest="";
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string res="";
        string curr1,curr2;
        bfs(root,startValue,curr1,this->start);
        bfs(root,destValue,curr2,this->dest);
        int p=0;
        while(p<this->start.size()&&p<this->dest.size()&&(this->start[p]==this->dest[p]))p++;
        this->start=this->start.substr(p);
        this->dest=this->dest.substr(p);
        res=string(this->start.size(),'U');
        res+=this->dest;
        return res;
    }

    void bfs(TreeNode* root,int v,string& curr,string& res){
        if(!root)return;
        if(root->val==v){
            res=curr;
            return;
        }
        if(root->left){
            curr+='L';
            bfs(root->left,v,curr,res);
            curr=curr.substr(curr.size()-1);
        }
        if(root->right){
            curr+='R';
            bfs(root->right,v,curr,res);
            curr=curr.substr(curr.size()-1);
        }
    }
}; 

 
 
 
int main(){
    Solution s;
}
