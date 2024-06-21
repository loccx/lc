#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    void fill(vector<vector<int>>& A,int r,int c){
        if(A[r][c]==1){
            A[r][c]=0;
            if(r>0)fill(A,r-1,c);
            if(c>0)fill(A,r,c-1);
            if(r<A.size()-1)fill(A,r+1,c);
            if(c<A[0].size()-1)fill(A,r,c+1);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        int count=0;
        for(int k=0;k<A.size();k++){
            fill(A,k,0);
            fill(A,k,A[0].size()-1);
        }
        for(int k=0;k<A[0].size();k++){
            fill(A,0,k);
            fill(A,A.size()-1,k);
        }
        for(auto k:A)for(int x:k)if(x==1)count++;
        return count;
    }
};
int main(){
    vector<int> inp={2,3,4,5,18,17,6};
    Solution s;
    cout<<s.maxArea(inp)<<endl;
}
