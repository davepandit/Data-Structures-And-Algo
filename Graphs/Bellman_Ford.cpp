#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> edges, int v, int s){
    // v is the no of nodes
    // s is the source node 
    // here we need to do the relaxation for v-1 times
    vector<int> ans(v, 1e8);
    ans[s] = 0;
    for(int i = 0; i < v-1; i++){
        // get the u, v and the wt from the edges 
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];

            // then do the relaxation thing 
            if(ans[v] != 1e8 && ans[u] + weight < ans[v]){
                // then we can replace the ans[v]
                ans[v] = ans[u] + weight;
            }
        }
    }
    // checking for the vth iteration to confirm whether there is a negative cycle or not 
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2]; 

        if(ans[v] != 1e8 && ans[u] + weight < ans[v]){
            return {-1};
        }
        // the logic behind this is like if there is a negative cycle then the value for the shortes
        // path will keep on getting reduced everytime so if that reduces the vth time then there is 
        // a cycle because we know that the max no of times we need to do the relaxation is like v-1 times
    }

    return ans;
}

int main(){
    return 0;
}