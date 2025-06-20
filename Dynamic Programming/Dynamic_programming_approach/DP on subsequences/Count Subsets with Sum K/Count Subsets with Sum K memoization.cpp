class Solution {
  public:
    int solve(int index, int sum, int target, vector<vector<int>>& dp, vector<int>& arr){
        if(index < 0){
            return sum == target ? 1 : 0;
        }

        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        // not pick
        int notPick = solve(index - 1, sum, target, dp, arr);

        // pick
        int pick = 0;
        if (sum + arr[index] <= target) {
            pick = solve(index - 1, sum + arr[index], target, dp, arr);
        }

        return dp[index][sum] = pick + notPick;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, 0, target, dp, arr);
    }
};
