#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstras(int v, vector<vector<int>> adj[], int s){
    // v is the no of nodes 
    // adj is the adjacency list 
    // s is the source node 
    // we need a priority queue for this 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // the above way of declaring the pq is to make the underlying structure as a min heap 
    vector<int> ans(v); // considering 0 based indexing 
    // making the distances as infinity 
    for(int i = 0; i < v; ++i){
        ans[i] = INT_MAX;
    }
    // in the pq the pair ka first int is the distance and the second int is node 
    pq.push({0, s}); // since the distance from the source node to itself is 0
    while(!pq.empty()){
        // get the top ele 
        int dis = pq.top().first;
        int node = pq.top().second;

        // check for the neighbours distance from the source node 
        // if the distance is lesser than what is there in the ans vector then we can insert 
        // that into the pq
        for(auto it : adj[node]){
            // it here is a vector which has 2 ele one being the node(the first one) and 
            // the second one being the distance
            int adjNode = it[0];
            int edgeWeight = it[1];

            // then we need to add the dis variable and the edgeWeight 
            if(dis + edgeWeight  < ans[adjNode]){
                // then we can push that into the ans
                ans[adjNode] = dis + edgeWeight;
                // then we can push that pair to the queue
                pq.push({ans[adjNode], adjNode});
            }
        }
    }

    return ans;

}

int main(){

    return 0;
}