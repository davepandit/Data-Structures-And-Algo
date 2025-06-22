class Solution {
public: 
    void solve(int index, vector<int>& op, vector<vector<int>>& ans, vector<int>& nums){
        if(index == nums.size()){
            // push whatever is there in op into ans
            ans.push_back(op);
            return;
        }

        // when we are taking -nums[index]
        op.push_back(-nums[index]);
        solve(index + 1, op, ans, nums);
        // revert back the changes made to op
        op.pop_back();

        // when we are taking nums[index]
        op.push_back(nums[index]);
        solve(index + 1, op, ans, nums);
        // revert back the changes made to op
        op.pop_back();
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // since here we have choices and based on those choices we can take 
        // some decisions so we will use recursion 

        int index = 0;
        vector<int> op;
        vector<vector<int>> ans;

        solve(index, op, ans, nums);

        // here ans is containing all the possible combinations 

        int res = 0;
        for(auto p : ans){
            int sum = 0;
            for(auto q : p){
                sum += q;
            }

            if(sum == target){
                res++;
            }
        }


        return res;
    }
};