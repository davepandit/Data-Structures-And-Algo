// User function Template for C++

class Solution {
  public:
    int solve(int index, int capacity, vector<vector<int>>& dp, vector<int>& val, vector<int>& wt){
        if(index == 0){
            return (capacity / wt[index]) * val[index];
        }
        
        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        // when we are not taking wt[index]
        int notTake = solve(index - 1, capacity, dp, val, wt);
        
        // when we are taking wt[index]
        int take = 0;
        if(capacity >= wt[index]){
            take = val[index] + solve(index, capacity - wt[index], dp, val, wt);
        }
        
        dp[index][capacity] = max(notTake, take);
        return dp[index][capacity];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // using recurrence relation 
        
        int n = val.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        
        return solve(index, capacity, dp, val, wt);
    }
};