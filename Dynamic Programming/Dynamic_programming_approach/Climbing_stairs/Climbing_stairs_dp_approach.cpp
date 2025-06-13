class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        // this is a very interesting/yaad karne wala soln at the very first instance😅
        // so first of all we are trying to solve the problem in terms of index, not sure why🐣, may be to reduce the time complexity because for the earlier soln, i was getting tle 

        // so in this problem we are actually counting the ways to reach the 0th step from every other step, so basically from the 0th step we have 1 ways to reach the 0th step, and from the 1st step we have 1 way to reach the 0th step, from the 2nd step we have 2 ways to reach the 0th step, this way 

        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};