class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        // base case here is also very critical 
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; ++k){
                if(p[k] != '*') return false;
            }

            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // when matches 
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        // this is also a very difficult question and it is absolutely okay 
        // to go to the lecture in order to revise this 

        int n = s.size(), m = p.size();
        int i = n - 1, j = m - 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(i, j, s, p, dp);
    }
};