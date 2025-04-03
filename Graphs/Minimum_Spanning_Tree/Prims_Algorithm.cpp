//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // algorithm 
        // 1. We will use a priority queue(min-heap)
        
        vector<int> visited(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // this is a min heap
        // {wt, node}
        pq.push({0, 0});
        int sum = 0; // this will return the sum of the minimum spanning tree 
        
        while(!pq.empty()){
            // take out the top one 
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(visited[node] == 1){
                continue;
            }
            
            visited[node] = 1;
            sum = sum + wt;
            
            // go along the adjacency list 
            for(auto it : adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                
                if(visited[adjNode] == 0){
                    // then push that into the queue
                    pq.push({wt, adjNode});
                }
            }
        }
        
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends