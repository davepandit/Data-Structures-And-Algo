class Solution {
public:
    void solve(int index, int& sum, int& count, int& amount, vector<int>& coins){
        if(index == coins.size()){
            if(sum == amount){
                count++;
            }

            return;
        }


        // when we are not taking coins[index] into sum 
        solve(index + 1, sum, count, amount, coins);

        // when we are taking coins[index] into sum 
        if(sum + coins[index] <= amount){
            sum += coins[index];
            solve(index, sum, count, amount, coins);
            // revert back the changes made to sum 
            sum -= coins[index];
        }
    }
    int change(int amount, vector<int>& coins) {
        // since we have some choices and based on those chocies 
        // we can take some decisions so we will use recursion here 

        int index = 0, sum = 0, count = 0;
        solve(index, sum, count, amount, coins);

        return count;
    }
};