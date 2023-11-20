#include <iostream>
#include <queue>

using namespace std;

bool canFinish(int num_courses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(num_courses, vector<int>()) // creates n nodes, and initializes neighbors to empty vectors
    vector<int> degree(num_courses, 0);

    for (auto &p : prerequisites) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }

    queue<int> q;
    for(int k = 0; k < num_courses; k++) {
        if (degree[k] == 0) q.push(k);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        num_courses--;
        for (auto next: adj[curr]) {
            if (--degree[next] == 0) { // decrement first, then check if it becomes 0
                q.push(next);
            }
        }
    }

    return num_courses == 0;
}

/*
bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}
*/

int main() {
}
