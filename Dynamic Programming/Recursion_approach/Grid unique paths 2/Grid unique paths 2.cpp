class Solution {
public:
    void solve(int x, int y, int& m, int& n, int& noOfWays, vector<pair<int, int>>& directions, vector<vector<int>>& obstacleGrid){
        if(x == m - 1 && y == n - 1){
            noOfWays++;
            return;
        }

        for(auto [di, dj] : directions){
            int ni = x + di;
            int nj = y + dj;

            if(ni < m && nj < n && obstacleGrid[ni][nj] != 1){ 
                solve(ni, nj, m, n, noOfWays, directions, obstacleGrid);
            }
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // since here we have somce choices and based on those choices we can take some decision
        // so we will use recursion here
        if(obstacleGrid[0][0] == 1){
            return 0; // there is no way to get to the target
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int noOfWays = 0;
        int x = 0, y = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}}; // this contains down, right directions
        solve(x, y, m, n, noOfWays, directions, obstacleGrid);

        return noOfWays;
    }
}; 