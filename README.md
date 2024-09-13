# Graph Coloring Problem Using AI (Backtracking) in C++

This repository contains a C++ implementation of the graph coloring problem using a backtracking algorithm. The goal is to assign colors to nodes in a graph such that no two adjacent nodes have the same color.

## Problem Description

The graph coloring problem involves assigning colors to nodes so that no two adjacent nodes share the same color. This solution uses a backtracking approach to determine if a valid coloring exists with a specified number of colors.

## Solution Approach

The solution uses the following approach:

- **`canColor`**: Checks if a node can be safely assigned a color, ensuring no two adjacent nodes share the same color.
- **`assignColors`**: Recursively attempts to assign colors to nodes. If a conflict arises, it backtracks and tries a different color.
- **`colorGraph`**: Starts the coloring process and invokes the recursive function.

## 5-Tuple Representation

Nodes are represented by a **5-tuple**:

```cpp
typedef tuple<int, int, int, int, int> Node;

##How to Run
g++ -o graph_coloring graph_coloring_problem.cpp
./graph_coloring

##Example 
Enter the number of nodes: 4
Enter the number of colors: 3
Enter the number of edges: 4
Enter the edges (u v) where u and v are node indices (0-based):
0 1
1 2
2 3
3 0

Solution found! Node colors are as follows:
Node 0 is colored with color 0
Node 1 is colored with color 1
Node 2 is colored with color 0
Node 3 is colored with color 1

##Contributing
This `README.md` is formatted to provide a clear and straightforward guide for users and contributors.


