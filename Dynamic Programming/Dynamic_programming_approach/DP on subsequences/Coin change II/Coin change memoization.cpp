class Solution {
public:
    int solve(int index, int target, vector<vector<int>>& dp, vector<int>& coins){
        if(index == 0){
            if(target % coins[index] == 0){
                return 1;
            }
            return 0;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        // when we are not taking coins[index] 
        int notTake = solve(index - 1, target, dp, coins);

        // when we are taking coins[index]
        int take = 0;
        if(coins[index] <= target){
            take = solve(index, target - coins[index], dp, coins);
        }

        dp[index][target] = (notTake + take);
        return dp[index][target];
    }
    int change(int amount, vector<int>& coins) {
        // using recurrence relation 
        int n = coins.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(index, amount, dp, coins);
    }
};