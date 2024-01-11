#include <iostream>
#include <queue>

using namespace std;

/*
There are a total of `n` courses you have to take, labeled from `0` to `n
- 1`. Some courses may have prerequisites, for example to take course `i`,
you have to first take all the courses it's prerequisite.
 
Given the `n` and an array `prerequisites` where `prerequisites[i]`
contains the pair `(ai, bi)` indicating that you must take course `bi`
before course `ai`.
 
Return if you can finish all courses. If yes, return true, else return
false.
*/

bool has_cycle(int k, vector<vector<int>>& prereq) {
    vector<bool> visited(false, int(prereq.size()));
    stack<int> s;
    s.push(prereq(k));
    visited[k] = true;

    while (!stack.empty()) {
        int curr = s.top();
        s.pop();

        for (auto p : prereq[curr]) {
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }
            else return true;
        }
    }

    return false;
}

bool courses_possible(vector<vector<int>>& prereq) {
    for (int k = 0; k < int(prereq.size()); k++) {
        if (dfs(k, prereq)) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "How many courses do you have to take?\n";
    cin >> n;

    vector<vector<int>> prerequisites = {};

    bool res = courses_possible(prerequisites);

    if (res) cout << "Possible!\n";
    else cout << "Not Possible.\n";

    return 0;
}
