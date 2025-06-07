class Solution {
public:
    void solve(int index, vector<int>& op, int n, int target, vector<vector<int>>& ans, vector<int>& candidates){
        if(target == 0){
            ans.push_back(op);
            return;
        }

        if(index == n || target < 0){
            return;
        }

        // when candidates[index] is not included 
        solve(index + 1, op, n, target, ans, candidates);

        // when candidates[index] is inlcuded
        if (target >= candidates[index]) {
            op.push_back(candidates[index]);
            solve(index, op, n, target - candidates[index], ans, candidates);
            op.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // here we have some choices and 
        // based on those choices we can take some decisions 
        // so we can use recursion here 

        vector<int> op;
        vector<vector<int>> ans;

        int index = 0;
        int n = candidates.size();
        solve(index, op, n, target, ans, candidates);
        return ans;
    }
};