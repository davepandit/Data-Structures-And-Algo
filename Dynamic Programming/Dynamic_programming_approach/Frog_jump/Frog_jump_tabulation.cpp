class Solution {
  public:
    int minCost(vector<int>& height) {
        // here we will use the tabulation method(bottom-up approach)
        
        int n = height.size();
        vector<int> dp(n, -1);
        
        dp[0] = 0;
        
        for(int i = 1; i < n; ++i){
            int left = dp[i - 1] + abs(height[i] - height[i - 1]); // taking one step 
            int right = INT_MAX;
            if(i - 2 >= 0){
                right = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            
            dp[i] = min(left, right);
        }
        
        return dp[n - 1];
        
    }
};