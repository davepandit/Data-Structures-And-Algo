#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstras(vector<vector<int>> adj[], int v, int s){
    // v is the no of nodes and s is the source node 
    // here we will be using the set 
    // the only thing is we need to to erase the pair from the set if there already exists
    // some pair that is lesser that the INT_MAX what that means is someone else has already found
    // a path but now we have discovered a path having lesser distance than that right 
    // so no need of checking of that 
    set<pair<int, int>> st;
    vector<int> ans(v);

    // fill it with the large values 
    for(int i = 0; i < v; ++i){
        ans[i] = INT_MAX;
    }

    // push the first thing into st
    st.insert({0, s}); // the first int is the distance and the seond one is the source node
    while(!st.empty()){
        // take out the first one 
        auto it = *(st.begin());
        // it here contains the pair 
        int node = it.second;
        int dis = it.first;

        for(auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(dis + edgeWeight < ans[adjNode]){
                // check if the adjNode is already node is already visited or not 
                if(ans[adjNode] != INT_MAX){
                    // then we can remove that pair from the set 
                    // and this is the only diff from the pq
                    st.erase({ans[adjNode], adjNode});
                }

                // now update the new value in the ans
                ans[adjNode] = dis + edgeWeight;
                st.insert({ans[adjNode], adjNode});
            }
        }
    }


    return ans;
}

int main(){
    // consider adj, v and s is given
    vector<int> res = dijkstras(adj, v, s);
    return 0;
}