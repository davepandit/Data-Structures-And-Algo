class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp){
        if(index == 0){
            return nums[index];
        }
        else if(index < 0){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int rob = nums[index] + solve(index - 2, nums, dp);
        int notRob = 0 + solve(index - 1, nums, dp);

        dp[index] = max(rob, notRob); 

        return dp[index];
    }
    int rob(vector<int>& nums) {
        // this is same as maximum sum of non adjacent ele 
        // but the only diff here is that the first and the last ele cannot be together 

        // we will first remove the first ele and then call the solve function 
        // we will then remove the last elel and then call the solve function 
        // and later we will return the max(ans1, ans2)

        if(nums.size() == 1){
            return nums[0];
        }


        int first = nums[0];
        nums.erase(nums.begin() + 0);
        int n = nums.size();

        vector<int> dp(n, -1);
        int ans1 = solve(n - 1, nums, dp);

        // inesert the ele at the first and remove the last one
        nums.insert(nums.begin() + 0, first);
        nums.erase(nums.begin() + nums.size() - 1);
        n = nums.size();

        // set dp to -1 
        for(int i = 0; i < n; ++i){
            dp[i] = -1;
        }
        int ans2 = solve(n - 1, nums, dp);

        return max(ans1, ans2);
    }
};