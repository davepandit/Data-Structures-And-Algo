class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& dp, vector<pair<int, int>>& directions){
        if(x == 0 && y == 0) {
            return 1;
        }
        if(x < 0 || y < 0) {
            return 0;
        }

        if(dp[x][y] != -1) {
            return dp[x][y];
        }

        dp[x][y] = 0; // initialize to 0 before accumulation

        for(auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if(nx >= 0 && ny >= 0) { // bounds check
                dp[x][y] += solve(nx, ny, dp, directions);
            }
        }

        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        int x = m - 1;
        int y = n - 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}}; // this marks the up and the left directions 

        return solve(x, y, dp, directions);
    }
};