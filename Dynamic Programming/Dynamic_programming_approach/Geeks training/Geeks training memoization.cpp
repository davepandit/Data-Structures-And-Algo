class Solution {
  public:
    int solve(int index, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(index == 0){
            int maxi = INT_MIN;
            // select the max but wo max nahi hona chahiye 
            for(int i = 0; i < 3; ++i){
                if(i != last){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            
            return maxi;
        }
        
        // before calling all this just check that whether we have the result already stored
        // somewhere or not
        if(dp[index][last] != -1){
            return dp[index][last];
        }
        
        // we have 3 choices - running, fighting, learning 
        
        int running = last != 0 ? arr[index][0] + solve(index - 1, 0, arr, dp) : 0;
        int fighting = last != 1 ? arr[index][1] + solve(index - 1, 1, arr, dp) : 0;
        int learning = last != 2 ? arr[index][2] + solve(index - 1, 2, arr, dp) : 0;
        
        dp[index][last] = max({running, fighting, learning});
        return dp[index][last]; // since we are passing 3 args to the max function we need to enclose them inside {}
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // since here we have choices and based on those choices we can 
        // take some decisions then we will use recursion 
        
        
        int n = arr.size();
        int last = 3;
        vector<vector<int>> dp(n, vector<int> (4, -1));
        
        return solve(n - 1, last, arr, dp);
    }
};