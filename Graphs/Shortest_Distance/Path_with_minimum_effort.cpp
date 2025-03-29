class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            // algorithm 
            // 1. We need to use the same Dijkstras algo here
            // 2. Store the diff and the x and the y in the queue
    
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
            int n = heights.size();
            int m = heights[0].size();
            vector<vector<int>> distance(n, vector<int> (m, 1e9));
    
            q.push({0, {0, 0}});
            distance[0][0] = 0;
    
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(!q.empty()){
                // take out the first one 
                auto it = q.top();
                q.pop();
                int diff = it.first;
                int x = it.second.first;
                int y = it.second.second;
    
                for(auto [dx, dy] : directions){
                    int nx = dx + x, ny = dy + y;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && max(diff, abs(heights[nx][ny] - heights[x][y])) < distance[nx][ny]){
                        distance[nx][ny] = max(diff, abs(heights[nx][ny] - heights[x][y]));
                        // push the updated distances into the queue
                        q.push({distance[nx][ny], {nx, ny}});
                    }
                }
            }
    
            if(distance[n-1][m-1] != 1e9){
                return distance[n-1][m-1];
            }
    
            return -1;
        }
    };