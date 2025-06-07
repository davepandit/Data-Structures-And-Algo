class Solution {
public:
    void solve(int index, vector<int> op, vector<int> nums, int n, vector<vector<int>>& ans){
        if(index == n){
            ans.push_back(op);
            return;
        }

        // when we are not taking nums[index] in the op

        int nextIndex = index + 1;
        while(nextIndex < n && nums[nextIndex] == nums[index]){
            nextIndex++;
        }

        solve(nextIndex, op, nums, n, ans);

        // when we are taking nums[index] into the op
        op.push_back(nums[index]);
        solve(index + 1, op, nums, n, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // this is the kind of a same solution as that of combination sum 2
        // since here we have some choices to make and 
        // based on those choices we can take some decisions so 
        // we will recursion here

        int index = 0;
        vector<int> op;
        vector<vector<int>> ans;
        int n = nums.size(); 

        sort(nums.begin(), nums.end());
        solve(index, op, nums,n, ans);

        return ans;
    }
};