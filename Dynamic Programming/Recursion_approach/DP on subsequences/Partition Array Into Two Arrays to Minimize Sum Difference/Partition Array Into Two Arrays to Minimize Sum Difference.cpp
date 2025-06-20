class Solution {
public:
    void solve(int index, vector<int>& op1, vector<int>& op2, vector<int>& ans, vector<int>& nums){
        if(index == nums.size()){
            int sum1 = 0, sum2 = 0;
            for(auto it : op1){
                sum1 += it;
            }

            for(auto it : op2){
                sum2 += it;
            }

            ans.push_back(abs(sum1 - sum2));
            return;
        }

        // when we are taking nums[index] into op1;
        if(op1.size() < nums.size() / 2){
            op1.push_back(nums[index]);
            solve(index + 1, op1, op2, ans, nums);
            // revert back the changes made to op1 
            op1.pop_back();
        }
        
        // when we are taking nums[index] into op2;
        if(op2.size() < nums.size() / 2){
            op2.push_back(nums[index]);
            solve(index + 1, op1, op2, ans, nums);

            // revert back the changes made to op2
            op2.pop_back();
        }
        
    }
    int minimumDifference(vector<int>& nums) {
        // since here we have some choices and based on those choices we can 
        // take some decisions so we will use recursion here

        int n = nums.size();
        int index = 0;
        vector<int> op1, op2, ans;

        solve(index, op1, op2, ans, nums);

        sort(ans.begin(), ans.end());

        return ans[0];
    }
};