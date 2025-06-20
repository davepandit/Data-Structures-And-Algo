class Solution {
  public:

    int solve(int index, int target, vector<vector<int>>& dp, vector<int>& arr){
        if(index == 0){
            if(target == 0 && arr[0] == 0) return 2; // pick or not pick
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int notPick = solve(index - 1, target, dp, arr);
        int pick = 0;
        if(target >= arr[index])
            pick = solve(index - 1, target - arr[index], dp, arr);
        
        return dp[index][target] = (pick + notPick);
    }

    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for(auto it : arr) sum += it;
        
        // Edge case: can't partition into such difference
        if(sum < d || (sum - d) % 2 != 0) return 0;
        
        int target = (sum - d) / 2;
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return solve(n - 1, target, dp, arr);
    }
};
