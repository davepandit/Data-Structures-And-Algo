//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool bfs(int src, vector<vector<int>>& adj, vector<int>& visited){
        visited[src] = 1;
        
        queue<pair<int, int>> q; // the firs int is the node and the other one is the parent from where it came from
        q.push({src, -1}); // lets say the starting node is coming from the position -1, since it is the first node
        
        while(!q.empty()){
            // get the first ele 
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacentNode : adj[node]){
                if(visited[adjacentNode] == 0){
                    // then okay and we can insert into the queue
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if(visited[adjacentNode] != 0 && parent != adjacentNode){
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
                if(bfs(i, adj, visited)) return true;
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