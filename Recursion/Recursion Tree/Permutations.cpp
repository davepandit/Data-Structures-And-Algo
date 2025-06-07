class Solution {
public:
    void solve(vector<int> ip, vector<int> op, vector<vector<int>>& ans){
        if(ip.size() == 0){
            ans.push_back(op);
            return;
        }

        for(int i = 0; i < ip.size(); ++i){
            vector<int> newIp = ip; // Make a copy
            vector<int> newOp = op; // Make a copy

            newOp.push_back(newIp[i]);
            newIp.erase(newIp.begin() + i);

            // call for the function 
            solve(newIp, newOp, ans);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // since here also we have some choices to make 
        // and based on those choices we can take some decisions 
        // so here we will use recursion 

        vector<int> op;
        vector<vector<int>> ans;
        
        solve(nums, op, ans);
        return ans;
    }
};