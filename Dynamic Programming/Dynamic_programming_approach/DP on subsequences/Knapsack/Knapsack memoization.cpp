class Solution {
  public:
    int solve(int index, int W, vector<vector<int>>& dp, vector<int>& val, vector<int>& wt){
        if(index == 0){
            if(W >= wt[index]){
                return val[index];
            }
            
            return 0;
        }
        
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        
        // when we are not taking that item 
        int notTake = 0 + solve(index - 1, W, dp, val, wt);
        
        // when we are taking that item
        int take = 0;
        if(W >= wt[index]){
            take = val[index] + solve(index - 1, W - wt[index], dp, val, wt);
        }
        
        dp[index][W] = max(notTake, take);
        
        return dp[index][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // using recurrence relation 
        
        int n = val.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        return solve(index, W, dp, val, wt);
    }
};