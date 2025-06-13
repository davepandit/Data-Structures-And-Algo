class Solution {
  public:
    int minCost(vector<int>& height) {
        // here the problem states that the frog can jump either one step 
        // or two steps but i am generalising it to k steps 
        // like the frog can jump k steps at max at a time say 
        
        int k = 2;
        int n = height.size();
        
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        for(int i = 1; i < n; ++i){
            vector<int> onePass;
            for(int j = 1; j <= k; ++j){
                if(i - j >= 0){
                    onePass.push_back(dp[i - j] + abs(height[i] - height[i - j]));
                }
            }
            
            // now we cam find the min from that array 
            sort(onePass.begin(), onePass.end());
            dp[i] = onePass[0];
        }
        
        
        return dp[n - 1];
        
    }
};