class Solution {
  public:
    int solve(int n, vector<int>& dp, vector<int>& height){
        if(n == 0){
            return 0; // means 0 se 0 pe jaane ka cost is 0
        }
        
        // before calling check whether we have the result of the overlapping subproblem stored somewhere
        if(dp[n] != -1){
            return dp[n];
        }
        
        int left = solve(n - 1, dp, height) + abs(height[n] - height[n - 1]); // here we are taking one step at a time
        int right = INT_MAX;
        if(n - 2 >= 0){
            right = solve(n - 2, dp, height) + abs(height[n] - height[n - 2]); // here we are taking 2 steps at a time
        }
        
        dp[n] = min(left, right);
        // since we need to return the min cost 
        return dp[n];
    }
    
    int minCost(vector<int>& height) {
        // using the dynamic programming approach
        // we know that there are overlapping subproblems 
        // again this is not very intutive😅
        
        
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, dp, height);
        
    }
};