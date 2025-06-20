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
        // using memoization
        // kya karna hai + kahan jaana hai 
        
        int n = arr.size();
        int index = n - 1;
        vector<vector<int>> dp(n + 1 , vector<int>(target + 1, -1));
        
        
        return solve(index, target, dp, arr);
    }
};