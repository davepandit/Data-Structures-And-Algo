//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // algorithm 
        // bfs is used here 
        queue<int> q; // store the node
        int n = adj.size();
        vector<int> dis(n, 1e9);
        vector<int> ans(n, -1);
        
        dis[src] = 0;
        // push that node into the queue
        q.push(src);
        
        while(!q.empty()){
            // take out the ele 
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(dis[node] + 1 < dis[it]){
                    dis[it] = dis[node] + 1;
                    // push that node into the queue
                    q.push(it);
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            if(dis[i] != 1e9){
                // change the ans 
                ans[i] = dis[i];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends