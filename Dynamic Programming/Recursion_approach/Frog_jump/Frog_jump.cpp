class Solution {
  public:
    void solve(int ip, int op, int& cost, vector<int>& height, vector<int>& ans){
        if(op == ip){
            ans.push_back(cost);
            return;
        }
        
        if(op + 1 <= ip){
            cost += abs(height[op + 1] - height[op]); // when we want to take 1 step at a tome 
            solve(ip, op + 1, cost, height, ans); // take one step
            // revert the change made to cost 
            cost -= abs(height[op + 1] - height[op]);
        }
        
        if(op + 2 <= ip){
            // again modify the cost 
            cost += abs(height[op + 2] - height[op]);
            solve(ip, op + 2, cost, height, ans);
            // revert the changes made to cost 
            cost -= abs(height[op + 2] - height[op]);
        }
    }
    int minCost(vector<int>& height) {
        // since here we have choices and based on those 
        // choices we can take some decisions then we will use recursion here
        
        int n = height.size();
        int ip = n - 1;
        int op = 0;
        int cost = 0;
        vector<int> ans;
        
        solve(ip, op, cost, height, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans[0];
        
    }
};