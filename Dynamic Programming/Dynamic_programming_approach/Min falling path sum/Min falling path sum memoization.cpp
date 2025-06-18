class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(x < 0 || y < 0 || y >= matrix[0].size()){
            return 200000; // this needs to be a big number so randomly i chose 200000
        }

        if(x == 0){
            return matrix[x][y];
        }

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        // in order to write any recurrence relation 
        //      kya karna hai + kahan jaana hai 
        int up = matrix[x][y] + solve(x - 1, y, matrix, dp);
        int upLeft = matrix[x][y] + solve(x - 1, y - 1, matrix, dp);
        int upRight = matrix[x][y] + solve(x - 1, y + 1, matrix, dp);

        dp[x][y] = min({up, upLeft, upRight});
        return dp[x][y];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // using recurrence relation 
        int n = matrix.size();

        int x = n - 1;
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int y = 0; y < n; ++y){
            int res = solve(x, y, matrix, dp);
            ans = res < ans ? res : ans;
        }


        return ans;
    }
};