class Solution {
public:
    int solve(int index, int target, vector<int>& coins){
        if(index == 0){
            if(target % coins[index] == 0){
                return target / coins[index];
            }

            return 1e9;
        }

        // when we are not taking coins[index] 
        int notTake = solve(index - 1, target, coins);
        // when we are taking coins[index]
        int take = INT_MAX;
        if(coins[index] <= target){
            take = 1 + solve(index, target - coins[index], coins);
        }


        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        // using recurrence 

        int n = coins.size();
        int index = n - 1;

        int res = solve(index, amount, coins);
        return res != 1e9 ? res : -1;
    }
};