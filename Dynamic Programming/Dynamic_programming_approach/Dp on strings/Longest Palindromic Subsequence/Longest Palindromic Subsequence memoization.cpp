class Solution {
public: 
    int solve(int index1, int index2, string& s, string& rev, vector<vector<int>>& dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        int notTake = max(solve(index1 - 1, index2, s, rev, dp), solve(index1, index2 - 1, s, rev, dp));

        int take = INT_MIN;
        if(s[index1] == rev[index2]){
            take = 1 + solve(index1 - 1, index2 - 1, s, rev, dp);
        }

        dp[index1][index2] = max(notTake, take);
        return dp[index1][index2];
    }
    int longestPalindromeSubseq(string s) {
        // i can reverse the string s and then can find the longest common 
        // subsequence in between the 2 

        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        int index1 = n - 1, index2 = n - 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(index1, index2, s, rev, dp);
    }
};