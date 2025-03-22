#include <bits/stdc++.h>
using namespace std;

int main(){
    // the first line of the input is about the no of nodes and the number of edges 
    int n , m; // n is the no of nodes and m is the no of edges 
    cin >> n >> m;
    int adj[n + 1][n + 1]; // if the ordering is 1 based then we consider the size to be n + 1
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        // mark the places of the edges as one 
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}