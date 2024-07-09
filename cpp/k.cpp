#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<queue>
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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() , cols = matrix[0].size();
        
        if(rows < 1){
            return 0;
        }

        printvec(matrix);
        // calculate prefix sum for rows
        for(int row = 0 ; row < rows ; row++){
            for(int col = 1 ; col < cols ;col++){
                matrix[row][col] =  matrix[row][col] + matrix[row][col -1];
            }
        }
        printvec(matrix);

        int count = 0 , sum ;
        cout<<"count: "<<count<<endl<<endl;
        unordered_map<int , int> counter;
        for(int colstart = 0 ; colstart < cols ;colstart++){
            for(int col = colstart ; col < cols; col++){
                cout<<"new column: "<<col<<endl;
                cout<<"clearing dictionary...\n";
                counter.clear();
                counter[0] = 1;
                cout<<"counter[0]: "<<counter[0]<<endl;
                sum =0;
                cout<<"clearing sum...\n";
                for(int row = 0 ; row < rows ;row++){
                    cout<<"k: "<<row<<endl;
                    cout<<"x: "<<col<<endl;
                    cout<<"matrix[row][col]: "<<matrix[row][col]<<endl;
                    sum += matrix[row][col] - (colstart > 0 ? matrix[row][colstart - 1] : 0 );
                    cout<<"sum: "<<sum<<endl;
                    count += (counter.find(sum-target) != counter.end() ? counter[sum-target] : 0);
                    cout<<"count updated: "<<count<<endl;
                    cout<<"incrementing counter[sum]: \n";
                    counter[sum]++;
                    cout<<"counter[sum]: "<<counter[sum]<<endl;
                    printmap(counter);
                    cout<<endl;
                }
                cout<<endl;
            }
            cout<<endl;
        }
        return count;
    }

    void printvec(vvi& v){
        cout<<"printed vec:\n";
        cout<<"   ";
        for(int k=0;k<v.size();k++)cout<<k<<' ';
        cout<<endl;
        for(int k=0;k<v.size();k++){
            cout<<k<<"| ";
            for(int x=0;x<v[0].size();x++){
                cout<<v[k][x]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void printmap(unordered_map<int,int>& mp){
        cout<<'{';
        for(auto p:mp){
            cout<<p.first<<":"<<p.second<<' ';
        }
        cout<<"}\n";
    }
};






int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vvi inp={{10,10,10,10},
             {10,1,1,10},
             {10,1,1,10},
             {10,10,10,10}};
    Solution s;
    cout<< s.numSubmatrixSumTarget(inp,4) <<endl;
    return 0;
}
