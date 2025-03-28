class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            // algorithm 
            // whenever there is a question of shortest path one of the algos that should come 
            // to our mind is dijkstras 
            // the only thing that we need to ponder on is whether we should use the 
            // queue one or the pq one or the set one 
            // here we will be using the queue one
            // since here we are given a matrix so we will convert our normal sa one directional 
            // distance vector to 2d
    
            queue<pair<int, pair<int, int>>> q; // the first one is the distance, the second one is the 
            // x cocrdinate and the third one is y coordinate
            int n = grid.size();
            int m = grid[0].size();
    
            if(grid[0][0] != 0 || grid[n-1][m-1] != 0){
                // then there is no point of running the algo 
                return -1;
            }
            if(grid[0][0] == 0 && (n == 1 && m == 1)){
                return 1;
            }
            vector<vector<int>> distance(n, vector<int> (m, 1e9));
    
            // push the src to the queue 
            q.push({1, {0, 0}});
            // mark the distance for the source as 0
            distance[0][0] = 1;
    
            // it is given that we can move around in the 8 directions 
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
    
            while(!q.empty()){
                // take out the front one 
                auto it = q.front();
                int dis = it.first;
                int x = it.second.first;
                int y = it.second.second;
    
                for(auto [di, dj] : directions){
                    int ni = di + x;
                    int nj = dj + y;
    
                    // check whether these nj and ni are within the ranges 
                    if(ni < n && ni >= 0 && nj < m && nj >= 0 && (grid[ni][nj] == 0) && (dis + 1 < distance[ni][nj])){
                        // then we can update the distance 
                        distance[ni][nj] = dis + 1;
                        // update the queue too
                        q.push({distance[ni][nj], {ni, nj}});
                    }
                }
            }
    
    
            if(distance[n-1][m-1] == 1e9){
                return -1;
            };
            return distance[n-1][m-1];
        }
    };