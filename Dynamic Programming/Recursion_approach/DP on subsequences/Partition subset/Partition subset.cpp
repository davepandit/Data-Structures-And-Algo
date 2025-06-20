class Solution {
public:
    bool solve(int index, vector<int>& op1, vector<int>& op2, vector<int>& nums){
        if(index == nums.size()){
            // check for the sum in the op1 and op1
            int sum1 = 0, sum2 = 0; 
            for(int i = 0; i < op1.size(); ++i){
                sum1 += op1[i];
            }

            for(int i = 0; i < op2.size(); ++i){
                sum2 += op2[i];
            }

            if(sum1 == sum2){
                return true;
            }
            else {
                return false;
            }
        }

        // when we take nums[index] into op1
        op1.push_back(nums[index]);
        bool left = solve(index + 1, op1, op2, nums);
        // revert back the changes made to op1
        op1.pop_back();

        // when we are taking the nums[index] into op2
        op2.push_back(nums[index]);
        bool right = solve(index + 1, op1, op2, nums);
        // revert back the changes made to op2
        op2.pop_back();

        return left || right; 
    }
    bool canPartition(vector<int>& nums) {
        // since here we have some choices and based on those 
        // choices we can take some decisions so we will use recursion hrere

        vector<int> op1, op2;
        int index = 0;

        return solve(index, op1, op2, nums);
    }
};