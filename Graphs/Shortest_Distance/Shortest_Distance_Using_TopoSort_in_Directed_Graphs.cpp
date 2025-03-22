//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void topoSort(vector<vector<pair<int, int>>>& adj, int src, stack<int>& st, vector<int>& visited){
        visited[src] = 1;
        
        for(auto it : adj[src]){
            if(visited[it.first] == 0){
                // call the dfs again
                topoSort(adj, it.first, st, visited);
            }
        }
        
        st.push(src);
    }
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        // algorithm 
        // 1. make the adjacency list as vector<vector<pair<int, int>>> where
        // the first int will store the node and the second one will store the 
        // distance
        // 2. Then do a topo sort and get the stack ready 
        // 3. keep on taking out the ele from the stack and just check for the 
        // adjacency nodes of the node taken and do the same distance wala thing
        // as we did in the bfs one 
        
        // v here is the no of vertices that we have 
        vector<vector<pair<int, int>>> adj(v); // the first int is the node
        // and the second one is the distance 
        for(auto it : edges){
            // it[0] is the src 
            // it[1] is the destination 
            // it[2] is the edge weight 
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // so we have made the adj list now 
        
        // time to do the topo sort 
        stack<int> st;
        int src = 0;
        vector<int> visited(v, 0);
        topoSort(adj, src, st, visited);
        
        // so now we have the stack ready
        vector<int> dist(v, 1e9);
        dist[src] = 0;
         
        while(!st.empty()){
            // take out the top
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        
        
        vector<int> ans(v, -1);
        
        for(int i = 0; i < v; ++i){
            if(dist[i] != 1e9){
                // then push that into the ans
                ans[i] = dist[i];
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends