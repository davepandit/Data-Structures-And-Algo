class Solution {
  public:
    void solve(int x, int y,string& op, vector<string>& ans, vector<vector<int>>& maze, vector<pair<int, int>>& directions, vector<vector<int>>& visited){
        if(x == maze.size() - 1 && y == maze.size() - 1){
            ans.push_back(op);
            return;
        }
        
        for(auto dir : directions){
            int di = dir.first;
            int dj = dir.second;
            int ni = x + di;
            int nj = y + dj;
            
            // check the position where we reached is a valid position or not
            if(ni < maze.size() && nj < maze.size() && nj >= 0 && ni >= 0 && maze[ni][nj] != 0){
                if(visited[ni][nj] != 1){
                    visited[ni][nj] = 1;
                    // then that is a correct position and we can inlcude that in out ans 
                    if(di == -1 && dj == 0){
                        op.push_back('U');
                    }
                    else if(di == 0 && dj == -1){
                        op.push_back('L');
                    }
                    else if(di == 1 && dj == 0){
                        op.push_back('D');
                    }
                    else if(di == 0 && dj == 1){
                        op.push_back('R');
                    }
                    
                    // call for the function again 
                    solve(ni, nj, op, ans, maze, directions, visited);
                    
                    // revert the changes made to op
                    op.pop_back();
                    // revert the change for visited too
                    visited[ni][nj] = 0;
                }
                
            }
            
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // since here we have choices and we can take some decisions 
        // based on those choices, so this is a problem of recursion 
        
        
        int n = maze.size();
        
        int x = 0;
        int y = 0;
        
        string op = "";
        vector<string> ans;
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        // we also need a matrix kind of a thing to store the visited nodes because  
        // we cannot take the path that is once visited 
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        if(maze[x][y] == 0){
            return ans;
        }
        
        visited[0][0] = 1;
        
        solve(x, y, op, ans, maze, directions, visited);
        
        // sort the array 
        sort(ans.begin(), ans.end());
        return ans;
    }
};