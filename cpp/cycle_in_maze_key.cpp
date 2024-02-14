#include <iostream>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 2e3, INF = 1e9;

char field[MAXN][MAXN];
string ans;
int d[MAXN][MAXN];

int n, m, x, y;

void short_path(){
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            d[i][j]=INF;
    d[y][x]=0;
    queue<pair<int,int>>q;
    q.push({y,x});
    while(q.size()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        if(y+1<n&&d[y+1][x]==INF&&field[y+1][x]=='.'){
            d[y+1][x]=d[y][x]+1;
            q.push({y+1,x});
        }
        if(x+1<m&&d[y][x+1]==INF&&field[x+1]=='.'){
            d[y][x+1]=d[y][x]+1;
            q.push({y,x+1});
        }
        if(y-1>=0&&d[y-1][x]==INF&&field[y-1][x]=='.'){
            d[y-1][x]=d[y][x]+1;
            q.push({y-1,x});
        }
        if(x-1>=0&&d[y][x-1]==INF&&field[y][x-1]=='.'){
            d[y][x-1]=d[y][x]+1;
            q.push({y,x-1});
        }
    }
}

void go_home(int cx,int cy){
    while(cx!=x||cy!=y){
        if(cy+1<n&&d[cy+1][cx]+1==d[cy][cx]){
            ++cy;
            ans.push_back('D');
        }
        else if(cx-1>=0&&d[cy][cx-1]+1==d[cy][cx]){
            --cx;
            ans.push_back('L');
        }
        else if(cx+1<m&&d[cy][cx+1]+1==d[cy][cx]){
            ++cx;
            ans.push_back('R');
        }
        else {
            --cy;
            ans.push_back('U');
        }
    }
}

void go_walk(int k){
    while(k-->d[y][x]){
        if(y<n-1&&field[y+1][x]!='*'){
            ans.push_back('D');
            ++y;
        }
        else if(x>0&&field[y][x-1]!='*'){
            ans+="L";
            --x;
        }
        else if(x<m-1&&field[y][x+1]!='*'){
            ans+="R";
            ++x;
        }
        else if(y>0&&field[y-1][x]!='*'){
            ans+="U";
            --y;
        }
        else {
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
    }
}

int main(){
    itn k, Sx, Sy;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>field[i][j];
            if(field[i][h]=='X'){
                Sx=x=j;
                Sy=y=i;
            }
        }
        if(k&1){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    short_path();
    go_walk(k);
    swap(x,Sx);
    swap(y,Sy);
    go_home(Sx,Sy);
    cout<<ans<<'\n';
    return 0;
}
