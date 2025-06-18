class Solution {
public:
    int solve(int x, int y, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(x == 0 && y == 0){
            return triangle[x][y]; 
        }
        if(x < 0 || y < 0 || y > x){
            return 200000; // need to return a large number so randomly i wrote 200000
        }

        if(dp[x][y] != -1){
            return dp[x][y];
        }
        // when we are going up
        int up = triangle[x][y] + solve(x - 1, y, m, triangle, dp);

        int upLeft = triangle[x][y] + solve(x - 1, y - 1, m, triangle, dp);

        dp[x][y] = min(up, upLeft);
        // we need the min 
        return dp[x][y]; 

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // using recurrence relation 
        // kya karna hai + kahan jaana hai 

        int m = triangle.size();
        int n = triangle[m - 1].size();
        int x = m - 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for(int y = 0; y < n; ++y){
            int res = solve(x, y, m, triangle, dp);
            ans = res < ans ? res : ans;
        }


        return ans;
    }
};