#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
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
        vector<bool> bfs(int source) const;
        bool isValidPath(const vector<int> & path) const;
        bool isReachable(int source, int dest)const;
        vector<int> findShortestPath(int src, int dest);

    private:
        unordered_map<int, list<int>> adjlist;
};


void graph::addEdge(int from, int to){
    adjlist[from].push_back(to);
    adjlist[to].push_back(from);
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

vector<int> graph::findShortestPath(int src, int dest) {
    stack s;
    s.push(src);
    vector<int> path;
    set<bool> v;

    int curr;
    while (s) {
        curr = s.top();
        s.pop();
        for (auto t : adjlist[curr]) {
        }

    }
}

/*
bool graph::isReachable(int source, int dest)const{
    auto visited = bfs(source);
    return visited[dest];
}


bool graph::isValidPath(const vector<int> & path) const{
    int n = path.size();
    for(int i = 0; i < n - 1; i++){
        if(!hasEdge(path[i], path[i+1])){
            return false;
        }
    }
    return true;

}
*/

vector<bool> graph::bfs(int source) const {
    int n = adjlist.size(); // number of vertices
    vector<bool> visited(n, false); // boolean vector of visited or not
    queue<int> q;

    visited[source] = true;
    q.push_back(source);

    int curr;
    while (q) {
        curr = q.pop_front();
        for (auto n : adjlist[curr]) {
            if (!visited[n]) {
                visited[n] = true;
                queue.push_back(n);
            }
        }
    }

    return visited;
     
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

    g.display();

    /*
    if (g.isValidPath(q)) cout << "exists " << '\n';
    else cout << "does not exist " << '\n';

    cout << "Is 6 reachable from 0? " << std::boolalpha << g.isReachable(0, 6) << '\n';
    */
    //cout << "shortest distance from 0 to 5 is " << '\n';
    //cout << "shortest path is: ";

    return 0;
}
