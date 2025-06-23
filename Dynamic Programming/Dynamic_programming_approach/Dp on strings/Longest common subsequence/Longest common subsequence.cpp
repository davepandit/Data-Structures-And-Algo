class Solution {
public:
    int solve(int index1, int index2, string& text1, string& text2, vector<vector<int>>& dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        // when we are not taking 
        int notTake1 = 0 + solve(index1 - 1, index2, text1, text2, dp);
        int notTake2 = 0 + solve(index1, index2 - 1, text1, text2, dp);

        int notTake = max(notTake1, notTake2);

        // when we are taking
        int take = INT_MIN;
        if(text1[index1] == text2[index2]){
            take = 1 + solve(index1 - 1, index2 - 1, text1, text2, dp);
        } 

        dp[index1][index2] = max(notTake, take);
        return dp[index1][index2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // using recurrence relation 

        // since here we need to report the longest so we need to 
        // return max(something, something) at the end

        int n1 = text1.size(), n2 = text2.size();
        int index1 = n1 - 1;
        int index2 = n2 - 1;
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(index1, index2, text1, text2, dp);
    }
};