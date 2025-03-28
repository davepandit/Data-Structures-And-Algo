#include <bits/stdc++.h>
using namespace std;

// this algo is same as the Dijkstras algo only, the only diff lies that we are using the 
// priority queue in the place of the normal queue 
vector<int> Dijkshtra(int src, vector<vector<pair<int, int>>> adj){
    // we use the min queue but the thing is like in c++ the default implementation of the 
    // queue is that of a max queue 
    int n = adj.size();  // the no of nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // this behind the scenes uses a min queue
    // the first int is the distance and the second int is the node ka value itself
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    pq.push({0, src});

    // the rest of the steps are same as that of bfs
    while(!pq.empty()){
        // take out the first pair 
        auto it = pq.top();
        pq.pop();
        int dis = it.first; // this is the distance 
        int node = it.second; // this is the node ka value 

        for(auto it : adj[node]){
            if(dis + it.second < distance[it.first]){
                // then we need to change the distance array 
                distance[it.first] = dis + it.second;
                // push the updated distance into the queue
                pq.push({distance[it.first], it.first});
            }
        }
    }

    // now the distance is ready 
    vector<int> ans(n, -1);
    for(int i = 0; i < n; ++i){
        if(distance[i] != 1e9){
            // then we need to update the ans
            ans[i] = distance[i];
        }
    }

    return ans;
}

int main(){
    return 0;
}