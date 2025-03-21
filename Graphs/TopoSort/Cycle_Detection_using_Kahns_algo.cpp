//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& indegree, vector<int>& visited, vector<int>& ans){
        // Create a queue for BFS
        queue<int> q;
        
        // Push all nodes with indegree 0 into the queue
        for(int i = 0; i < adj.size(); ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            // Take out the front element
            int node = q.front();
            q.pop();
            
            // Add it to the answer
            ans.push_back(node);
            
            for(auto it : adj[node]){
                // Reduce the indegree of the adjacent nodes
                indegree[it] = indegree[it] - 1;
                if(indegree[it] == 0){
                
                    q.push(it);
                }
            }
        }
    }
    
    // Function to return list containing vertices in Topological order.
    bool topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of nodes
        vector<int> indegree(n, 0);
        
        // Compute the indegree of each node
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < adj[i].size(); ++j){
                // Increment indegree of the adjacent node
                indegree[adj[i][j]] = indegree[adj[i][j]] + 1;
            }
        }
        
        // Initialize visited array
        vector<int> visited(n, 0);
        vector<int> ans;
        
        // Process each unvisited node
        bfs(0, adj, indegree, visited, ans);
        
        // here we have got the ans 
        // so we need to check for the number of ele in the ans 
        // because we know that kahns algo work for the DAG
        // so basically if there is a cycle then the linear ordering that we
        // used to get we will not be getting that 
        if(ans.size() != n){
            return true; // cycle exists
        }

        // otherwise return false 
        return false;
    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends