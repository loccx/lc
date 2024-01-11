#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//my solution
/*
class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraphKey(Node* node) {
        if (!node) return node;
        if (visited.count(node)) return visited[node];

        Node* copy = new Node(node->val);
        visited[node] = copy;

        for (auto n : node->neighbors) { 
            copy->neighbors.push_back(cloneGraph(n));
        }

        return copy;
    }

};
*/

void bfs(Node* start, int nodeCount) {
    vector<bool> visited(nodeCount, false);

    if (!start) {
        cout << "empty graph\n";
        return;
    }

    deque<Node*> q;
    q.push_back(start);
    visited[start->val] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->val << " ";
        q.pop_front();

        for (auto n : curr->neighbors) {
            if (!visited[n->val]) {
                q.push_back(n);
                visited[n->val] = true;
            }
        }
    }
    cout << '\n';
    return;
}

int main() {

    // sample graph
    Node* node0 = new Node(0);
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);

    node0->neighbors.push_back(node9);
    node0->neighbors.push_back(node7);
    node0->neighbors.push_back(node11);
    node1->neighbors.push_back(node10);
    node1->neighbors.push_back(node8);
    node2->neighbors.push_back(node3);
    node2->neighbors.push_back(node12);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node3->neighbors.push_back(node7);
    node4->neighbors.push_back(node3);
    node5->neighbors.push_back(node6);
    node6->neighbors.push_back(node5);
    node6->neighbors.push_back(node7);
    node7->neighbors.push_back(node11);
    node7->neighbors.push_back(node0);
    node7->neighbors.push_back(node3);
    node7->neighbors.push_back(node6);
    node8->neighbors.push_back(node1);
    node8->neighbors.push_back(node12);
    node8->neighbors.push_back(node9);
    node10->neighbors.push_back(node1);
    node10->neighbors.push_back(node9);
    node11->neighbors.push_back(node7);
    node11->neighbors.push_back(node0);
    node12->neighbors.push_back(node2);
    node12->neighbors.push_back(node9);

    bfs(node0, 12);

    return 0;
}
