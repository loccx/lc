/*
// Definition for a Node.
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
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return node;
        if (visited.count(node)) return visited[node];

        Node* copy = Node(node->val);
        visited[node] = copy;

        for (auto n : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(n));
        }
        return cloneGraph(node);
    }
};
