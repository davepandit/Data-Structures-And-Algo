class Solution {
public:
    int solve(int index, int target, vector<vector<int>>& dp, vector<int>& coins){
        if(index == 0){
            if(target % coins[index] == 0){
                return target / coins[index];
            }

            return 1e9;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        // when we are not taking coins[index] 
        int notTake = solve(index - 1, target, dp, coins);
        // when we are taking coins[index]
        int take = INT_MAX;
        if(coins[index] <= target){
            take = 1 + solve(index, target - coins[index], dp, coins);
        }

        dp[index][target] = min(notTake, take);
        return dp[index][target];
    }
    int coinChange(vector<int>& coins, int amount) {
        // using recurrence 

        int n = coins.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = solve(index, amount, dp, coins);
        return res != 1e9 ? res : -1;
    }
};