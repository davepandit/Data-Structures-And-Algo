class Solution {
public:
    int solve(int index, int target, vector<int>& nums){
        if(index == 0){
            if(target == 0 && nums[index] == 0){
                return 2;
            }
            if(target - (-nums[index]) == 0){
                return 1;
            }
            if(target - nums[index] == 0){
                return 1;
            }

            return 0;
        }


        // when we take -nums[index]
        int negative = solve(index - 1, target - (-nums[index]), nums);

        // when we take nums[index]
        int positive = solve(index - 1, target - nums[index], nums);

        return (negative + positive);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // using recurrence relation 

        int n = nums.size();

        int index = n - 1;

        return solve(index, target, nums);
    }
};