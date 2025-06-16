class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& dp){
        if(x == 0 && y == 0){
            return 1;
        }
        if(x < 0 || y < 0){
            return 0;
        }

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        // when we are moving up
        int up = solve(x - 1, y, dp); // reduce x by 1 
        // when we are moving left 
        int left = solve(x, y - 1, dp); // reduce y by 1
        dp[x][y] = up + left;

        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        // using recurrence relaion 


        int x = m - 1;
        int y = n - 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(x, y, dp);
    }
};