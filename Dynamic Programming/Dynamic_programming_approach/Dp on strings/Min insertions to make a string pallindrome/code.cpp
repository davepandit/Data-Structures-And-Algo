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
    int minInsertions(string s) {
        // this can be a very difficult problem if we want to solve it in a 
        // typical way 
        // this needs to be solved using the LCS and the longest pallindromic subsequence concepts 


        string rev = s;
        reverse(rev.begin(), rev.end());
        int index1 = s.size() - 1, index2 = rev.size() - 1;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        int longestPallindromicSubsequence = solve(index1, index2, s, rev, dp);

        return s.size() - longestPallindromicSubsequence;
    }
};