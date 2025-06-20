class Solution {
public:
    bool solve(int index, int& sum1, int& sum2, vector<int>& nums){
        if(index == 0){
            if((sum1 + nums[index] == sum2) || (sum1 == sum2 + nums[index])){
                return true;
            }
            else{
                return false;
            }
        }

        // we can either take nums[index] into op1 means into sum1 or into op2 or sum2

        // when taken into sum1 
        sum1 += nums[index];
        bool takenIntoSum1 = solve(index -1, sum1, sum2, nums);

        // revert back the changes made to sum1 
        sum1 -= nums[index];

        // when taken into sum2
        sum2 += nums[index];
        bool takenIntoSum2 = solve(index - 1, sum1, sum2, nums);

        // revert back the changes made to sum2
        sum2 -= nums[index];

        return (takenIntoSum1 || takenIntoSum2);
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int index = n - 1;
        int sum1 = 0, sum2 = 0;

        return solve(index, sum1, sum2, nums);
    }
};