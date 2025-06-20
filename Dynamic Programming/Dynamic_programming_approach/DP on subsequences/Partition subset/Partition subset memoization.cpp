class Solution {
public:
    bool solve(int index, double target, vector<vector<int>>& dp, vector<int>& arr){
        if(target == 0){
            return true;
        }
        else if(index == 0 && arr[index] == target){
            return true;
        }
        else if(index == 0 && arr[index] != target){
            return false;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        // when we dont include that arr[index] into the ans 
        bool notPick = solve(index - 1, target, dp, arr);
        
        // when we include that arr[index] into the ans 
        bool pick = false;
        if(target >= arr[index]){
            pick = solve(index - 1, target - arr[index], dp, arr);
        }
        
        dp[index][target] = pick || notPick;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        // this is the same as the subset sum problem 
        // we simply need to find whether the sum/2 exists or not

        int sum = 0;
        for(auto it : nums){
            sum += it;
        }

        int n = nums.size();
        int index = n - 1;
        double target = double(sum) / 2;
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));

        return solve(index, target, dp, nums);
    }
};