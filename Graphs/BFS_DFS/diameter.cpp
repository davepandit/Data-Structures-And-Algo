#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to perform BFS and return the farthest node and its distance
    pair<int, int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1); // Distance array
        queue<int> q;
        
        q.push(start);
        dist[start] = 0; 
        
        int farthestNode = start;
        int maxDist = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { // If not visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    
                    // Update farthest node and max distance
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return {farthestNode, maxDist};
    }

    // Function to compute the diameter of the graph
    int findDiameter(vector<vector<int>>& adj) {
        if (adj.empty()) return 0;

        // Step 1: Run BFS from any node (we pick node 0)
        pair<int, int> firstBFS = bfs(0, adj);

        // Step 2: Run BFS from the farthest node found
        pair<int, int> secondBFS = bfs(firstBFS.first, adj);

        // The maximum distance in the second BFS gives the diameter
        return secondBFS.second;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
    
    Solution obj;
    cout << "Diameter of the graph: " << obj.findDiameter(adj) << endl;
    
    return 0;
}
