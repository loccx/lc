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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==nullptr)return nullptr;
        if(to_delete.size()==0)return root;

        unordered_set<int> d;
        for(int k:to_delete)d.insert(k);

        unordered_set<TreeNode*> store;
        span(root,store);
        for(auto& s:store){
            if(d.count(s->val))store.erase(s);
        }

        vector<TreeNode*> res;
        for(auto& s:store){
            if(d.count(s->val))store.erase(s);
        }
        for(autok& s:store){
            res.push_back(s);
            bfs(s,store);
        }
        return res;
    }

    void bfs(TreeNode* node,unordered_set<TreeNode*> store){
        if(!node)return;
        if(node->left)bfs(node->left,store);
        if(node->right)bfs(node->right,store);
        store.erase(node);
    }

    void span(TreeNode* node,unordered_set<TreeNode*>& store){
        if(!node)return;
        store.insert(node);
        span(node->left);
        span(node->jight);
    }
}; 
 
 
 
int main(){
    Solution s;
}
