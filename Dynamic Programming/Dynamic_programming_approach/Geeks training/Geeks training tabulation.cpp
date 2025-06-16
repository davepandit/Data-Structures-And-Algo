class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // tabulation 
        
        int n = arr.size();
        int index = 0;
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        for(int i = 0; i < 4; i++){
            if(i == 0){
                dp[index][i] = max(arr[index][1], arr[index][2]);
            }
            else if(i == 1){
                dp[index][i] = max(arr[index][0], arr[index][2]);
            }
            else if(i == 2){
                dp[index][i] = max(arr[index][0], arr[index][1]);
            }
            else if(i == 3){
                dp[index][i] = max({arr[index][0], arr[index][1], arr[index][2]});
            }
        }
    
        
        for(int i = 1; i < n; ++i) {
            for(int last = 0; last < 4; ++last) {
                dp[i][last] = 0;
                for(int task = 0; task < 3; ++task) {
                    if(task != last) {
                        int point = arr[i][task] + dp[i - 1][task];
                        dp[i][last] = max(dp[i][last], point);
                    }
                }
            }
        }
        
        
        return dp[n - 1][3];
        
    }
};