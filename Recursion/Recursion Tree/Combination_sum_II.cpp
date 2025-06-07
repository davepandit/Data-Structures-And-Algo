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

        int nextIndex = index + 1;
        while (nextIndex < n && candidates[nextIndex] == candidates[index]) {
            nextIndex++;
        }

        // When candidates[index] is not included
        solve(nextIndex, op, n, target, ans, candidates);

        // when candidates[index] is inlcuded
        if (target >= candidates[index]) {
            op.push_back(candidates[index]);
            solve(index + 1, op, n, target - candidates[index], ans, candidates);
            op.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> op;
        vector<vector<int>> ans;

        int index = 0;
        int n = candidates.size();

        sort(candidates.begin(), candidates.end());
        solve(index, op, n, target, ans, candidates);

        return ans;
    }
};