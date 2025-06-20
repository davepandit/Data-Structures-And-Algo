class Solution {
  public:
    bool solve(int index, int target, vector<vector<int>>& dp, vector<int>& arr){
        if(target == 0){
            return true;
        }
        else if(index == 0 && arr[index] == target){
            return true;
        }
        else if(index == 0 && arr[index] != target){
            return false;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        // when we dont include that arr[index] into the ans 
        bool notPick = solve(index - 1, target, dp, arr);
        
        // when we include that arr[index] into the ans 
        bool pick = false;
        if(target >= arr[index]){
            pick = solve(index - 1, target - arr[index], dp, arr);
        }
        
        dp[index][target] = pick || notPick;
        return dp[index][target];
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // using tabulation
        
        int n = arr.size();
        vector<vector<bool>> dp(n , vector<bool>(target + 1, false));
        
        // mark the base cases
        for(int i = 0; i < n; ++i){
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        // remember the no of changing states that are there 
        // utne hi loop we need to use 
        for(int i = 1; i < n; ++i){
            for(int k = 1; k <= target; k++){
                bool notPick = dp[i -  1][k];
                
                bool pick = false;
                if(k >= arr[i]){
                    pick = dp[i - 1][k - arr[i]];
                }
                
                dp[i][k] = pick || notPick;
            }
        }
        
        
        return dp[n - 1][target];
        
        
        
    }
};