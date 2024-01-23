#include <iostream>
#include <queue>

using namespace std;

void dx(vector<vector<char>>& maze, vector<vector<int>>& dist, int Sx, int Sy) {
    dist[Sx][Sy] = 0;
    queue<pair<int, int>> q;
    q.push({Sx, Sy});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        if (x < int(maze.size()-1) && dist[x+1][y] == INT_MAX && maze[x+1][y] == '*') {
            dist[x+1][y] = dist[x][y] + 1;
            q.push({x+1, y});
        }
        if (x > 0 && dist[x-1][y] == INT_MAX && maze[x-1][y] == '*') {
            dist[x-1][y] = dist[x][y] + 1;
            q.push({x-1, y});
        }
        if (y < int(maze[0].size()-1) && dist[x][y+1] == INT_MAX && maze[x][y+1] == '*') {
            dist[x][y+1] = dist[x][y] + 1;
            q.push({x, y+1});
        }
        if (y > 0 && dist[x][y-1] == INT_MAX && maze[x][y-1] == '*') {
            dist[x][y-1] = dist[x][y] + 1;
            q.push({x, y-1});
        }
    }
}

int main() {
    int r, c;
    cin>>r>>c;

    vector<vector<char>> maze(r, vector<char>(c));
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

    int Sx, Sy;

    for(int k=0;k<r;k++){
        for(int i=0;i<c;i++){
            cin>>maze[k][i];
            if (maze[k][i] == 'S') {
                Sx = k;
                Sy = i;
            }
        }
    }


    dx(maze, dist, Sx, Sy);

    for(int k=0;k<r;k++){
        for(int i=0;i<c;i++){
            if (dist[k][i] != INT_MAX) cout << dist[k][i] << " ";
            else cout << -1 << " ";
        }
        cout<<'\n';
    }
}

/*
   empty space: *
obstacle: X
start: S
*/
