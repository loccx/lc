#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <unordered_map>

using namespace std;

class graph {
    public:
        graph (int n) {
            adjlist = unordered_map<int, list<int>>(n); // the inner loop is a list, implemented as linkednodes, for quick access to the edges?? or something but i thought traversing a vector in contiguous memory was faster than traversing a linkedlist 
}
        void addEdge(int from, int to);
        bool hasEdge(int i, int j) const;
        void display() const;
        void bfs(int source);
        void dfs(int source);

    private:
        unordered_map<int, list<int>> adjlist;
};


void graph::addEdge(int from, int to){
    adjlist[from].emplace_back(to);
    adjlist[to].emplace_back(from);
}

bool graph::hasEdge(int from, int to) const {
    for (auto e : adjlist.at(from)) if (e == to) return true;
    return false;
}

void graph::display() const {
    for (auto &m : adjlist) {
        cout << m.first << "->: ";
        for (auto to : m.second) {
            cout << to << " ";
        }
        cout << '\n';
    }
}

#ifdef DEBUG
void p_set(unordered_set<int>& st) {
    for (auto s : st) {
        cout << s << " ";
    }
    cout << '\n';
}
#endif

void graph::bfs(int source) {
    unordered_set<int> visited;
    queue<int> q;
    visited.insert(source);
    q.push(source);

    while (q.size()) {

        int curr = q.front();
        q.pop();
        cout << "curr: " << curr << '\n';

        for (auto k : adjlist[curr]) {
#ifdef DEBUG
            p_set(visited);
#endif
            if (visited.find(k) == visited.end()) {
                visited.insert(k);
                q.push(k);
            }
        }
    }
}

void graph::dfs(int source) {
    unordered_set<int> visited;
    stack<int> q;
    visited.insert(source);
    q.push(source);

    while (q.size()) {

        int curr = q.top();
        q.pop();
        cout << "curr: " << curr << '\n';

        for (auto k : adjlist[curr]) {
#ifdef DEBUG
            p_set(visited);
#endif
            if (visited.find(k) == visited.end()) {
                visited.insert(k);
                q.push(k);
            }
        }
    }
}

int main() {  
    graph g(8);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 1);
    g.addEdge(5, 4);
    g.addEdge(6, 1);
    g.addEdge(6, 5);
    g.addEdge(7, 6);
    g.addEdge(7, 5);
    g.addEdge(23, 6);
    g.addEdge(23, 1);
    g.addEdge(23, 3);

    g.display();

    g.bfs(2);
    cout << '\n';
    g.dfs(2);

    return 0;
}
