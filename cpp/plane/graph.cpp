#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
    private:
        unordered_map<int, list<pair<int, int>>> adjlist;
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

        int dijkstra(int a, int b) {
            unordered_map<int, pair<int, bool>> distances;
            for (auto node : adjlist) {
                distances[node.first] = {INT_MAX, false}; // default distance for every node in the graph is inf, and unvisited
            }

            stack<int> s;
            s.push(a);
            distances[a] = {0, true}; // distance from starter node is 0, and is now visited

            while (!s.empty()) { // dfs
                int curr = s.top();
                s.pop();

                for (auto next : adjlist[curr]) {
                    int curr_to_next_dist = 
                    distances[next].first = min(distances[next].first, distances[curr].first + adjlist[curr])
                }
            }
        }
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
