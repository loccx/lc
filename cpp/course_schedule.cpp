#include <iostream>
#include <queue>

using namespace std;

bool canFinish(int num_courses, vector<pair<int, int>>& prerequisites) {
    //adj = unordered_map<int, list<int>>;
        
    vector<list<int>> adj;
    vector<int> deg;

    // builds the adjacency list
    for (auto p : prerequisites) {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

}

int main() {
    vector<pair<int, int>> input = {{1,2},{0,1}};
    if (canFinish(2, input)) cout << "finished!\n";
    else cout << "not finished.\n";
}
