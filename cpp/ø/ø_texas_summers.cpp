#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <set>

#define ll long long
#define endl '\n'
#define fork(a,b) for(ll k=a;k<=b;k++)
#define fori(a,b) for(ll i=a;i<=b;i++)
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;
const ll K=3e3;

int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void dijkstra(int graph[K][K], int source, int nodesCount) {
    vector<int> distance(nodesCount, INT_MAX);
    vector<int> pred(nodesCount, -1);
    set<pair<int, int>> pq;

    distance[source] = 0;
    pq.insert({0, source});
    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        for(int v=0;v<nodesCount;v++){
            if(distance[v]>distance[u]+graph[u][v]){
                pq.erase({distance[v], v});
                distance[v]=distance[u]+graph[u][v];
                pred[v]=u;
                pq.insert({distance[v],v});
            }
        }
    }

    stack<int> path;
    int curr = nodesCount - 1;
    while(curr!=-1){
        path.push(curr);
        curr=pred[curr];
    }

    if (path.size()==2) {
        cout<<"-\n";
        return;
    }

    path.pop();
    while (path.size()>1) {
        cout << path.top()-1 << " ";
        path.pop();
    }
    cout << endl;
    return;
}

int main() {
    vector<pair<int, int>> shades;
    vector<pair<int, int>> nodes;

    int shade_count;
    cin >> shade_count;
    for (int i = 0; i < shade_count; i++) {
        int x, y;
        cin >> x >> y;
        shades.push_back({x, y});
    }

    int startx, starty;
    cin >> startx >> starty;
    int endx, endy;
    cin >> endx >> endy;

    nodes.push_back({startx, starty});
    for (int k = 0; k < shades.size(); k++) {
        nodes.push_back(shades[k]);
    }
    nodes.push_back({endx, endy});

    int graph[K][K];
    for (int k = 0; k < nodes.size(); k++) {
        for (int i = 0; i < nodes.size(); i++) {
            graph[k][i] = dist(nodes[k].first, nodes[k].second, nodes[i].first, nodes[i].second);
        }
    }

    dijkstra(graph, 0, nodes.size());

    return 0;
}

