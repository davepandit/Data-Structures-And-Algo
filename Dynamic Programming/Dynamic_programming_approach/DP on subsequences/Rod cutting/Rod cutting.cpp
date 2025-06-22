// User function Template for C++

class Solution {
  public:
    int solve(int index, int rodLength, vector<vector<int>>& dp, vector<int>& price){
        if(index == 0){
            return (rodLength / (index + 1)) * price[index];
        }
        
        if(dp[index][rodLength] != -1){
            return dp[index][rodLength];
        }
        
        // when we are not taking price[index]
        int  notTake = solve(index - 1, rodLength, dp, price);
        
        // when we are taking price[index]
        
        int take = 0;
        if(rodLength >= (index + 1)){
            take = price[index] + solve(index, rodLength - (index + 1), dp, price);
        }
        
        dp[index][rodLength] = max(notTake, take);
        return dp[index][rodLength];
    }
    int cutRod(vector<int> &price) {
        // this is a tricky question 
        // this is kind of same as that of the knapsack problem 
        
        int n = price.size();
        int rodLength = n; // this info is missing in the question 
        
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(index + 2, -1));
        
        return solve(index, rodLength, dp, price);
        
    }
};