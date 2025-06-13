// User function template for C++
class Solution {
  public:
    int solve(int index, vector<int>& dp, vector<int>& arr){
        if(index == 0){
            return arr[index];
        }
        if(index < 0){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        // if we are picking an ele
        int pick = arr[index] + solve(index - 2, dp, arr);
        
        // if we are not picking an ele 
        int notPick = 0 + solve(index - 1, dp, arr);
        
        dp[index] = max(pick, notPick);
        
        // now we need to return the max 
        return dp[index];
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // again this is not very intutive at the first sight 
        // but kind of following the same pattern 
        // as the frog jump and the climbing stairs
        // one very imp thing to note in this problem is like we are 
        // always starting from the back 
        
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(n - 1, dp, arr);
    }
};