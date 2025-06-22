class Solution {
public: 
    void solve(int index, int& sum, int count, int& minCount, int& amount, vector<int>& coins){
        if(index == coins.size()){
            // check whether the sum is equal to the amount or not
            if(sum == amount){
                minCount = count < minCount ? count : minCount;
            }

            return; 
        }

        // when we are not taking coins[index]
        solve(index + 1, sum, count, minCount, amount, coins);

        // when we are taking coins[index]
        if((long long)sum + coins[index] <= amount){
            sum += coins[index];
            count++;
            solve(index, sum, count, minCount, amount, coins);
            // revert back the changes made to sum 
            sum -= coins[index];
        }

    }
    int coinChange(vector<int>& coins, int amount) {
        // since here we have some choices and based on those choices 
        // we can take some decisions so we will use recursion here 

        int n = coins.size();
        int index = 0, count = 0, minCount = INT_MAX, sum = 0;

        solve(index, sum, count, minCount, amount, coins);

        return minCount != INT_MAX ? minCount : -1;
    }
};