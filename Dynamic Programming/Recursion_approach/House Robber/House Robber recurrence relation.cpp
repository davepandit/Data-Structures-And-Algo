class Solution {
public:
    int solve(int index, vector<int>& nums){
        if(index == 0){
            return nums[index];
        }
        else if(index < 0){
            return 0;
        }

        int rob = nums[index] + solve(index - 2, nums);
        int notRob = 0 + solve(index - 1, nums);

        return max(rob, notRob);
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
        int ans1 = solve(n - 1, nums);

        // inesert the ele at the first and remove the last one
        nums.insert(nums.begin() + 0, first);
        nums.erase(nums.begin() + nums.size() - 1);
        n = nums.size();

        int ans2 = solve(n - 1, nums);

        return max(ans1, ans2);
    }
};