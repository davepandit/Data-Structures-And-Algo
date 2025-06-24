class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // this is also a very difficult problem of we dont know the concept of 
        // LCS and printing the LCS

        // logic : keep the LCS intact and then we just need to add the left over stuffs 
        // in the same order anywhere to the LCS 

        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Fill LCS DP table
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Build SCS by tracing back from dp[n][m]
        int i = n, j = m;
        string res = "";

        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                res += str1[i - 1];
                i--;
                j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                res += str1[i - 1];
                i--;
            } else {
                res += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters
        while(i > 0) res += str1[i-- - 1];
        while(j > 0) res += str2[j-- - 1];

        reverse(res.begin(), res.end());
        return res;
    }
};