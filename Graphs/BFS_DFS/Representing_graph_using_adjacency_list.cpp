#include <bits/stdc++.h>
using namespace std;

int main(){
    // the first line is the no of nodes and the no of edges that are there 
    int n, m;
    vector<int> adj[n + 1]; // this means in every index of the array we are having one vector 
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}