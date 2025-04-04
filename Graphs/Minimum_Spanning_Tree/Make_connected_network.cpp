class DisjointSet{
    vector<int> size, parent;
    public: 
    int extraEdges = 0;
        // n is the no of nodes that are there
        DisjointSet(int n){
            size.resize(n, 1);
            parent.resize(n);

            // initialise every value in parent with itself
            for(int i = 0; i < n; ++i){
                parent[i] = i;
            }
        }

        // now we need to implement 2 functions 
        // one is findUltParent 
        // second one is UnionBySize

        int findUltParent(int u){
            if(parent[u] == u){
                return u;
            }

            return parent[u] = findUltParent(parent[u]);
        }

        void UnionBySize(int u, int v){
            // u and v are supposed to be connected
            // find the ult parent of u and v 
            // find the size of u and v 
            // connect the one having the smaller size with the one having the larger size

            int ult_u = findUltParent(u);
            int ult_v = findUltParent(v);

            if(ult_u == ult_v){
                // then we can increase the no of extra edges 
                extraEdges++;
                return;
            }

            if(size[ult_u] < size[ult_v]){
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else{
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
};

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        queue<int> q;
        q.push(node);

        visited[node] = 1;

        while(!q.empty()){
            // take out the first one 
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    // push it into the queue
                    q.push(it);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1; // Not enough edges anyway

        DisjointSet ds(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            ds.UnionBySize(u, v);
        }

        int components = 0;
        for(int i = 0; i < n; ++i){
            if(ds.findUltParent(i) == i) components++;
        }

        if(ds.extraEdges >= components - 1){
            return components - 1;
        }

        return -1;

    }
};