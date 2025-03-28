#include <bits/stdc++.h>
using namespace std;


vector<int> Dijkshtra(int src, vector<vector<pair<int, int>>> adj){
    
    int n = adj.size();  // the no of nodes
    set<pair<int, int>> st; // the first one is the distance and the second one is the node ka value
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    st.insert({0, src});

    // the rest of the steps are same as that of bfs
    while(!st.empty()){
        // auto it = st.begin(); // remember this is an iterator and isse humara kaam nahi hoga 
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;

        for(auto it : adj[node]){
            if(dis + it.second < distance[it.first]){
                // also need to check that the adjacency node's distance is less than infinity or
                // not because then that path needs to be removed 
                if(distance[it.first] < 1e9){
                    // then we can erase that pair from the set 
                    st.erase({distance[it.first], it.first});
                }

                // now we can push the updated distance into the set 
                distance[it.first] = dis + it.second;
                st.insert({distance[it.first], it.first});
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