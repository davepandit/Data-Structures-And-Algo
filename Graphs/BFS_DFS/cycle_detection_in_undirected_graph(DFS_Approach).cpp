//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        
        // iterate over the adjacentNodes
        for(auto adjacentNode : adj[node]){
            if(visited[adjacentNode] == 0){
                // call for the function again
                if(dfs(adjacentNode, node, adj, visited)){
                    return true; // means agar kisine bhi true return kar diya hai then for sure
                    // there is a cycle and all can return a true
                }
                else if(parent != adjacentNode){
                    // then there is a cycle 
                    return true;
                }
            }
        }
        
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        
        // check for the diff components if any 
        vector<int> visited(n, 0);

        for(int i = 0; i < n; ++i){
            if(visited[i] == 0){
                // then only do the traversal 
                if(dfs(i, -1, adj, visited)) return true;
            }
        }
        
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends