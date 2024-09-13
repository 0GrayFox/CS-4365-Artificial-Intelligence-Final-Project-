#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// The tuple represents a node with (node_id, color, degree, x, y)
typedef tuple<int, int, int, int, int> Node;

// Function to check if the current color assignment is valid for the node
bool canColor(vector<Node>& nodes, vector<vector<int>>& adjMatrix, int nodeIndex, int color) {
    for (int i = 0; i < nodes.size(); i++) {
        if (adjMatrix[nodeIndex][i] == 1 && get<1>(nodes[i]) == color) {
            return false; // Adjacent node has the same color
        }
    }
    return true;
}

// Recursive function to assign colors using backtracking
bool assignColors(vector<Node>& nodes, vector<vector<int>>& adjMatrix, int nodeIndex, int totalColors) {
    if (nodeIndex == nodes.size()) {
        return true; // All nodes are successfully colored
    }

    for (int color = 0; color < totalColors; color++) {
        if (canColor(nodes, adjMatrix, nodeIndex, color)) {
            get<1>(nodes[nodeIndex]) = color; // Assign the color to the current node

            // Recursively assign colors to the next node
            if (assignColors(nodes, adjMatrix, nodeIndex + 1, totalColors)) {
                return true;
            }

            // Backtrack if the color assignment doesn't work
            get<1>(nodes[nodeIndex]) = -1;
        }
    }

    return false; // No valid coloring found
}

// Function to start the graph coloring process
bool colorGraph(vector<Node>& nodes, vector<vector<int>>& adjMatrix, int totalColors) {
    return assignColors(nodes, adjMatrix, 0, totalColors);
}

int main() {
    int numNodes, numEdges, totalColors;

    // Input: Number of nodes and colors
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    cout << "Enter the number of colors: ";
    cin >> totalColors;

    // Initialize nodes
    vector<Node> nodes;
    for (int i = 0; i < numNodes; i++) {
        int degree = 0, x = 0, y = 0;  // Degree, x, y can be assigned as needed
        nodes.push_back(make_tuple(i, -1, degree, x, y));  // Initial color is -1 (uncolored)
    }

    // Initialize adjacency matrix (graph structure)
    vector<vector<int>> adjMatrix(numNodes, vector<int>(numNodes, 0));

    // Input: Number of edges
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (u v) where u and v are node indices (0-based):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        get<2>(nodes[u])++;  // Increment the degree of node u
        get<2>(nodes[v])++;  // Increment the degree of node v
    }

    // Solve the graph coloring problem
    if (colorGraph(nodes, adjMatrix, totalColors)) {
        cout << "Solution found! Node colors are as follows:" << endl;
        for (const auto& node : nodes) {
            cout << "Node " << get<0>(node) << " is colored with color " << get<1>(node) << endl;
        }
    } else {
        cout << "No solution exists with " << totalColors << " colors." << endl;
    }

    return 0;
}
