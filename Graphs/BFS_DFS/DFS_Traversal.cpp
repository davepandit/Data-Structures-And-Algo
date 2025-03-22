#include <bits/stdc++.h>
using namespace std;

void solve(int start, vector<vector<int>>& adj, int visited[], vector<int> ls){
    // as soon as the starting node comes then we have seen that so basically the visited should be updated
    visited[start] = 1;
    // can include it in the traversal wala array too
    ls.push_back(start);

    for(auto it : adj[start]){
        if(!visited[it]){
            solve(it, adj, visited, ls);
        }
    }
}

vector<int> dfs(int n, vector<vector<int>>& adj){
    int visited[n] = {0}; // considering 0 based indexing
    int start = 0;
    vector<int> ls;
    solve(start, adj, visited, ls);

    return ls;

}

int main(){
    // making the adjacency list
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int starting_node = 0; // this is simply a starting node
    vector<int> ans = dfs(n, adj);

    for(auto it : ans){
        cout << it;
    }
    return 0;
}