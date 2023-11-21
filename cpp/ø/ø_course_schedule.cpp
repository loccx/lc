#include <iostream>
#include <queue>

using namespace std;

bool canFinish(int num_courses, vector<pair<int, int>>& prerequisites) { // this implementation works because the value of the node corresponds to the number of nodes there are
    vector<vector<int>> al(num_courses, vector<int>()); // adjacency list implementation for the courses
    vector<int> degree(num_courses, 0); // in-degree for each node, n nodes each degree start with 0

    for (auto &p : prerequisites) {
        al[p.second].push_back(p.first);
        degree[p.first]++;
    }

    queue<int> q;

    for (int k = 0; k < num_courses; k++) {
        if (degree[k] == 0) q.push(k);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        num_courses--;
        for (auto c : al[curr]) {
            if (--degree[c] == 0) q.push(c);
        }
    }
    return num_courses == 0;
}

int main() {
    vector<pair<int, int>> input = {{1,0},{0,1}};
    if (canFinish(2, input)) cout << "finished!\n";
    else cout << "not finished.\n";
}
