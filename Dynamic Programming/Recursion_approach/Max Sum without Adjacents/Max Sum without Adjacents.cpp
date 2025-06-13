// User function template for C++
class Solution {
  public:
    void solve(int index, vector<int>& op, vector<int>& ip, vector<vector<int>>& ans, vector<int>& store){
        if(index == ip.size()){
            ans.push_back(op);
            return;
        }
        
        // when we are not including 
        solve(index + 1, op, ip, ans, store);
        
        // when we are including 
        if(store.empty() || store[store.size() - 1] != index - 1){
            store.push_back(index);
            op.push_back(ip[index]);
            
            // call for the function again 
            solve(index + 1, op, ip, ans, store);
            
            // revert back the changes made to op and store
            op.pop_back();
            store.pop_back();
        }
        
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // since here we have some choices and based on those choices 
        // we can take some decisions then we can use recursion here
        
        vector<vector<int>> ans;
        vector<int> op;
        int index = 0;
        vector<int> store;
        
        solve(index, op, arr, ans, store);
        
        int maxSum = INT_MIN;
        
        for(auto it : ans){
            int sum = 0;
            for(auto ele : it){
                sum += ele;
            }
            
            maxSum = sum > maxSum ? sum : maxSum;
        }
        
        return maxSum;
        
    }
};