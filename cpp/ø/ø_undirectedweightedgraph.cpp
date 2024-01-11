#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits.h>

using namespace std;

/*
This graph implementation:
vector<list<pair>>
UNDIRECTED, WEIGHTED, GRAPH
implements dijkstra's
*/

class SimpleGraph {
    private:
        vector<list<pair<int, int>>> adjlist;

    public:
        SimpleGraph() {}

        SimpleGraph(int n) : adjlist(n) {}

        void edge(int src, int dest, int w) { // weighted graph
            adjlist[src].push_back({dest, w});
            adjlist[dest].push_back({src, w});
        }

        void print_adjlist() {
            for (int k = 0; k < int(adjlist.size()); k++) {
                cout << k << ": ";
                for (auto x : adjlist[k]) {
                    cout << x.first << "," << x.second << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }

        void dijkstra(int src) {
            int V = adjlist.size(); //num of vertices

            vector<int> distances(V, INT_MAX); // set all distances to max, except source node
            distances[src] = 0;

            vector<bool> visited(V, false); // // boolean array to keep track of which nodes have been visited

           priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // the point of the priority queue is that when we pick the next node to traverse to, we must traverse to the node with the shortest path from the current one. the priority queue maintains so that the shortest path node is always the one on top
            pq.push({0, src}); // push distance 0, first node

            while (!pq.empty()) {
                auto top = pq.top(); //get minimum distance from top of the queue 
                pq.pop();

                int curr = top.second; // vertex with the current shortest distance
                visited[curr] = true;

                for (auto k : adjlist[curr]) {
                    int v = k.first;
                    int weight = k.second;

                    if (!visited[v] && distances[curr] != INT_MAX && distances[curr] + weight < distances[v]) {
                        distances[v] = distances[curr] + weight;
                        pq.push({distances[v], v});
                    }
                }
            }

            for (int k = 0; k < V; k++) { // output distances to each other node
                if (k != src) {
                    cout << src << "->" << k << " : " << distances[k] << '\n';
                }
            }
        }
};

int main() {
    int inp;
    cout << "how many nodes in your graph? (-1 for indeterminate)";
    cin >> inp;
    SimpleGraph g(inp);

    g.edge(0, 2, 3);
    g.edge(0, 5, 2);
    g.edge(2, 4, 1);
    g.edge(2, 3, 4);
    g.edge(3, 1, 1);
    g.edge(2, 5, 2);
    g.edge(5, 4, 3);
    g.edge(5, 6, 5);
    g.edge(6, 1, 2);
    g.edge(4, 1, 2);
    g.edge(5, 1, 6);

    g.print_adjlist();

    g.dijkstra(0);
}
