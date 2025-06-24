class Solution {
public:
    int solve(int index1, int index2, string& word1, string& word2, vector<vector<int>>& dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        int notTake = max(solve(index1 - 1, index2, word1, word2, dp), solve(index1, index2 - 1, word1, word2, dp));

        int take = INT_MIN;
        if(word1[index1] == word2[index2]){
            take = 1 + solve(index1 - 1, index2 - 1, word1, word2, dp);
        }

        dp[index1][index2] = max(notTake, take);
        return dp[index1][index2];
    }
    int minDistance(string word1, string word2) {
        // this is also a hard problem agar humne pehle 
        // LCS nahi kar rakha hai to 

        int n = word1.size(), m = word2.size();

        int index1 = n - 1, index2 = m - 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int LCS = solve(index1, index2, word1, word2, dp);

        return (n - LCS) + (m - LCS);
    }
};