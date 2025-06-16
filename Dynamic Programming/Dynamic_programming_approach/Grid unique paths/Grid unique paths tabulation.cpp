class Solution {
public:
    int uniquePaths(int m, int n) {
        // using tabulation

        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[0][0] = 1;
        int negative = 0;

        for(int x = 0; x < m; ++x){
            for(int y = 0; y < n; ++y){
                if(x == 0 && y == 0){
                    dp[x][y] = 1;
                    continue;
                }
                // when we are moving up
                int up = (x - 1 < 0) ? negative : dp[x - 1][y]; // reduce x by 1 
                // when we are moving left 
                int left = (y - 1 < 0) ? negative : dp[x][y - 1]; // reduce y by 1

                dp[x][y] = up + left;
            }
        }
        

        return dp[m - 1][n - 1];
    }
};