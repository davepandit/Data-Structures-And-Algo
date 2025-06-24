class Solution {
public:
    int solve(int index1, int index2, string& s1, string& s2, vector<vector<int>>& dp){
        if(index1 < 0){
            return index2 + 1;
        }
        if(index2 < 0){
            return index1 + 1;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(s1[index1] == s2[index2]){
            return dp[index1][index2] = solve(index1 - 1, index2 - 1, s1, s2, dp);
        }
        else{
            int insert = 1 + solve(index1, index2 - 1, s1, s2, dp);
            int del = 1 + solve(index1 - 1, index2, s1, s2, dp);
            int replace = 1 + solve(index1 - 1, index2 - 1, s1, s2, dp);

            return dp[index1][index2] = min({insert, del, replace});
        }
    }
    int minDistance(string word1, string word2) {
        // this is again a difficult problem and it is okay 
        // if we need to see the solution while revising the problem 

        int n = word1.size(), m = word2.size();
        int index1 = n - 1, index2 = m - 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(index1, index2, word1, word2, dp);
    }
};