class DisjointSet{
    vector<int> size, parent;
    public:
        // n is the no of nodes
        DisjointSet(int n){
            size.resize(n, 1); // size is initialiased to 1
            parent.resize(n);

            for(int i = 0; i < n; ++i){
                parent[i] = i;
            }
        }

        // here we need to implement 2 functions 
        // one is the find ultimate parent 
        int findUltParent(int u){
            if(parent[u] == u){
                return u;
            }
            return parent[u] = findUltParent(parent[u]);
        }

        // second one is the union by size 
        void UnionBySize(int u, int v){
            // here we will be joining the 2 nodes 
            int ulp_u = findUltParent(u);
            int ulp_v = findUltParent(v);

            if(ulp_u == ulp_v){
                return;
            }

            if(size[ulp_u] < size[ulp_v]){
                // connect the smaller one to the larger one 
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // algorithm 
        // What i am seeing in the problems is we need to make some sort of graph 
        // by doing the union and then we need to count the no of components 
        // here also the final answer is = n - no of components 
        // first we need to make the maxRow and the maxCol 

        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // now we need to make the graph and then we need to count the no f components
        DisjointSet ds(maxRow + maxCol + 2);
        unordered_set<int> usedNodes;
        for(auto it : stones){
            int x = it[0];
            int y = it[1];

            // join the x and y
            // but remember before joining we need to keep one thing in mind that is 
            // some of the rows will never get into union because it may be possible that 
            // there is no stone in the row 2 say 
            int rowNode = x;
            int colNode = y + maxRow + 1;
            ds.UnionBySize(rowNode, colNode);
            usedNodes.insert(rowNode);
            usedNodes.insert(colNode);
        }

        // now we have made the graph 
        // now we need to count the no of components 
        int components = 0;
        for(auto it : usedNodes){
            if(ds.findUltParent(it) == it){
                components++;
            }
        }

        // final ans = n - no of components 
        return n - components;
    }
};