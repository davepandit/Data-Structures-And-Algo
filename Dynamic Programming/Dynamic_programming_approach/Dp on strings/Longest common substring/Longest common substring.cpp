class Solution {
  public:
    int longestCommonSubstr(string& text1, string& text2) {
        // using tabultaion 
        
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // base case
        for(int i = 0; i <= n; ++i){
            dp[i][0] = 0;
        }

        for(int j = 0; j <= m; ++j){
            dp[0][j] = 0;
        }

        // do stuffs on rest of the stuffs 
        int ans = 0;
        for(int index1 = 1; index1 <= n; ++index1){
            for(int index2 = 1; index2 <= m; ++index2){
                if(text1[index1 - 1] == text2[index2 - 1]){
                    int val = 1 + dp[index1 - 1][index2 - 1];
                    dp[index1][index2] = val;
                    
                    ans = max(ans, val);
                } 
                else{
                    dp[index1][index2] = 0;
                }
            }
        }

        return ans;
        
    }
};