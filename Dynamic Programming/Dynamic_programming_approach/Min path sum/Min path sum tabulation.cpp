class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // using tabulation 

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

       
        int negative = 200000;

        for(int x = 0; x < m; ++x){
            for(int y = 0; y < n; ++y){
                if(x == 0 && y == 0){
                    dp[0][0] = grid[0][0];
                    continue;
                }
                int up = grid[x][y] + ((x - 1 < 0) ? negative : dp[x - 1][y]);
                int left = grid[x][y] + ((y - 1 < 0) ? negative : dp[x][y - 1]);

                dp[x][y] = min(up, left);
            }
        }

        return dp[m - 1][n - 1];
    }
};