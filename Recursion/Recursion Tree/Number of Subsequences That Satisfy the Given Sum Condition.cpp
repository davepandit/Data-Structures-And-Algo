class Solution {
public:
    void solve(vector<int> ip, vector<int> op, vector<vector<int>>& ans){
        if(ip.size() == 0){
            if(op.size() != 0){
                ans.push_back(op);
            }
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);

        // make the input smaller 
        ip.erase(ip.begin());

        // call for the function again 
        solve(ip, op1, ans);
        solve(ip, op2, ans);
    }
    int numSubseq(vector<int>& nums, int target) {
        // here we are having some choices and based on those choices we can take some 
        // decisions so here we can use recursion 

        vector<int> op;
        vector<vector<int>> ans; 

        // sort the nums before passing into the function because doing so 
        // hume baad me smaller and larger no nikalne ke liye kuch extra nahi karna padega 
        sort(nums.begin(), nums.end());
        solve(nums, op, ans);

        // now we have the answer as 
        // ans = {{3}, {2}, {2, 3}, {1}, {1, 3}, {1, 2}, {1, 2, 3}}
        long long count = 0; 
        for(auto p : ans){
            int min = p[0];
            int max = p[p.size() - 1];

            if(min + max <= (long long)target){
                count++;
            }
        }

        long long MOD = 1e9 + 7;
        count = count % MOD;

        return (int)count;
    }
};