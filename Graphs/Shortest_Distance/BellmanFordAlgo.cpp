//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // algorithm 
        // 1. It is kinda similar to Dijkstras only, but here we dont use the priority queue
        // 2. Also this is very useful when there are negative weights in the graph
        // and also it is used to detect that whethere there is any cycle that 
        // contains negative edge 
        // 3. Concept is here we need to do the edge relaxation part n - 1 times
        vector<int> distance(V, 1e8);
        distance[src] = 0;
        
        for(int i = 1; i <= V - 1; ++i){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // do the relaxation
                if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                }
            }
        }
        
        // so typically we would have returned something as 
        // return distance;
        
        // but here the question asks to check for cycle with negative weights also 
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
                return {-1};
            }
        }
        
        return distance;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends