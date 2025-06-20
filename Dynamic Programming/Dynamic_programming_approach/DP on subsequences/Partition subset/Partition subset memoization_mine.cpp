class Solution {
public:
    bool solve(int index, int& sum1, int& sum2, vector<vector<vector<int>>>& dp, vector<int>& nums){
        if(index == 0){
            if((sum1 + nums[index] == sum2) || (sum1 == sum2 + nums[index])){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[index][sum1][sum2] != -1){
            return dp[index][sum1][sum2];
        }

        // we can either take nums[index] into op1 means into sum1 or into op2 or sum2

        // when taken into sum1 
        sum1 += nums[index];
        bool takenIntoSum1 = solve(index -1, sum1, sum2, dp, nums);

        // revert back the changes made to sum1 
        sum1 -= nums[index];

        // when taken into sum2
        sum2 += nums[index];
        bool takenIntoSum2 = solve(index - 1, sum1, sum2, dp, nums);

        // revert back the changes made to sum2
        sum2 -= nums[index];

        dp[index][sum1][sum2] = (takenIntoSum1 || takenIntoSum2);
        return dp[index][sum1][sum2];
    }
    bool canPartition(vector<int>& nums) {
        // using memoization 

        int n = nums.size();
        int index = n - 1;
        int sum1 = 0, sum2 = 0;

        // the size of one dimension of the dp is basically the sum of all the ele 
        // because we for sure know that sum of ele in nums se zyada to store karne ka need nahi hai

        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(sum, vector<int>(sum, -1)));

        return solve(index, sum1, sum2, dp, nums);
    }
};