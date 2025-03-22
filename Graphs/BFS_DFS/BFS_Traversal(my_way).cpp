#include <bits/stdc++.h>
using namespace std;

void level_order_traversal(int starting_node, vector<vector<int>>& adj, vector<int>& visited) {
    queue<int> q;
    q.push(starting_node);

    // Mark the starting node as visited
    visited[starting_node] = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            // Take out the front element
            int front_ele = q.front();
            q.pop();

            // Print the current node
            cout << front_ele << " ";

            // Check all adjacent nodes
            for (int j = 0; j < adj[front_ele].size(); ++j) {
                int neighbor = adj[front_ele][j];
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = 1; // Mark neighbor as visited
                }
            }
        }
    }
}

int main() {
    int n, m;
    // n is the number of nodes, m is the number of edges
    cin >> n >> m;

    // Make the adjacency list (1-based indexing)
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; // Read the nodes that have an edge between them
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create a visited array
    vector<int> visited(n + 1, 0);

    // Perform level-order traversal for all components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            level_order_traversal(i, adj, visited);
            cout << endl; // Separate components by a newline
        }
    }

    return 0;
}
