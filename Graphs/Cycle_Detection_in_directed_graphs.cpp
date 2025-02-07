#include <bits/stdc++.h>
using namespace std;

bool dfs(int s, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path_visited){
    visited[s] = 1;
    path_visited[s] = 1;

    for(auto it : adj[s]){
        // here we iterate over the ele that are there in the adjacency list 
        if(visited[it] == 0){
            // then we can call for the dfs again
            if(dfs(it, adj, visited, path_visited)){
                return true;
            }
        }
        else if(path_visited[it] == 1){
            return true;
        }
    }

    // here we need to make the path_visited of the s as 0 again 
    path_visited[s] = 0;

    // here we can return a false
    return false;
}

bool containsCycle(vector<vector<int>>& adj){
    int n = adj.size(); // getting the size that how many nodes are there
    // we will be using the dfs only to find out is there any cycle or not
    // for that we need to make a visited array as usual but we also need a path visited array 
    vector<int> visited(n, 0);
    vector<int> path_visited(n, 0); // when we will marking the ele as visited that time only we will be marking the path as visited 
    // but when we are returning from the path then we will again marking that path as non visited 
    for(int i = 1; i <= n; ++i){
        if(visited[i] == 0){
            // call for the dfs 
            if(dfs(1, adj, visited, path_visited)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    // consider we are given a adj list as adj
    bool ans = containsCycle(adj);
    cout << ans;
    return 0;
}