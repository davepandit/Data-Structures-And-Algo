class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // using tabulation 
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int outOfBounds = 1e9;

        // base case 
        for(int y = 0; y < n; ++y){
            dp[0][y] = matrix[0][y];
        }

        // express all states in the loop
        for(int x = 1; x < n; ++x){
            for(int y = 0; y < n; ++y){
                int up = matrix[x][y] + ((x - 1 < 0) ? outOfBounds : dp[x - 1][y]);
                int upLeft = matrix[x][y] + ((x - 1 < 0 || y - 1 < 0) ? outOfBounds : dp[x - 1][y - 1]);
                int upRight = matrix[x][y] + ((x - 1 < 0 || y + 1 >= n) ? outOfBounds : dp[x - 1][y + 1]);

                dp[x][y] = min({up, upLeft, upRight});
            }
        }

        int result = INT_MAX;
        for (int y = 0; y < n; ++y) {
            result = min(result, dp[n - 1][y]);
        }
        return result;

    }
};