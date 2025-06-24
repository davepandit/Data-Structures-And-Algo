#include <bits/stdc++.h>
using namespace std;

void solve(string& s1, string& s2, int n, int m, vector<vector<int>>& dp){
    // base case 
    for(int i = 0; i <= n; ++i){
        dp[i][0] = 0;
    }

    for(int j = 0; j <= m; ++j){
        dp[0][j] = 0;
    }

    // do stuffs on rest of the states 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void printLCS(int i, int j, int& index, string& s1, string& s2, string& ans, vector<vector<int>>& dp){
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            ans[index] = s1[i - 1];
            index = index - 1;
            i = i - 1;
            j = j - 1;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i = i - 1;
        }
        else if(dp[i - 1][j] < dp[i][j - 1]){
            j = j - 1;
        }
    }
}
int main(){
    string s1 = "abcde";
    string s2 = "abe";

    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    solve(s1, s2, s1.size(), s2.size(), dp);

    int LCS = dp[n][m]; // this is the length of the LCS

    int i = n, j = m;

    string ans(LCS, '$');

    int index = LCS - 1;
    printLCS(i, j, index, s1, s2, ans, dp);

    cout << "LCS: " << ans;

    return 0;
}