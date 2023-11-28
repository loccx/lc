#include <iostream>
#include <vector>
#include <map>

class Wgraph { private:
    int V; // Number of vertices
    std::map<int, std::vector<std::pair<int, int>>> adjList; // Adjacency list with weights

public:
    Wgraph(int vertices) : V(vertices) {}

    // Function to add a weighted directed edge to the graph
    void addEdge(int from, int to, int weight) {
        adjList[from].emplace_back(to, weight);
    

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (const auto& entry : adjList) {
            std::cout << entry.first << " |";
            for (const auto& edge : entry.second) {
                std::cout << " (-> " << edge.first << ", W: " << edge.second << ")";
            }
            std::cout << '\n';
        }
    }

    int countVertices() {
        return V;
    }
};

int main() {
    Wgraph g(3);

    // Add weighted directed edges
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 5);

    // Print the adjacency list representation of the weighted directed graph
    g.printGraph();

    return 0;
}
