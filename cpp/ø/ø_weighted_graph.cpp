#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Graph {
    private:
        unordered_map<int, list<pair<int, int>>> adjlist; // .first is the destination node, .second is the weight of the edge
        unordered_set<int> nodes;

    public:
        Graph() {}

        void add_edge(int a, int b, int weight) { // directed edge between nodes a and b
            adjlist[a].push_back({b, weight});
        }

        void print_adjlist() {
            for (auto a : adjlist) {
                cout << a.first << ": ";
                for (auto l : a.second) {
                    cout << l.first << ',' << l.second << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }

        /*
        int dijkstra(int src, int dst) {
            return 0;
        }
        */

};

int main() {
    Graph g;
 
    int a = -1, b = -1, weight = -1;
    while (a != 0 || b != 0 || weight != 0) {
        cout << "Enter a and b nodes to connect\n";
        cin >> a >> b >> weight;
        if (a != 0 || b != 0 || weight != 0) g.add_edge(a, b, weight);
    }
    g.print_adjlist();
}
