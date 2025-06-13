// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // this is a tabulation soln the memoization soln can be found on github
        
        int n = arr.size();
        vector<int> dp(n, -1);
        
        dp[0] = arr[0];
        int negative = 0;
        
        for(int i = 1; i < n; ++i){
            int pick = arr[i] + ((i - 2 < 0) ? negative : dp[i - 2]);
            int notPick = 0 + dp[i - 1];
            
            dp[i] = max(pick, notPick);
        }
        
        
        return dp[n - 1];
        
    }
};