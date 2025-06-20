class Solution {
  public:
    void solve(int index, int& sum, vector<int>& ans, vector<int>& arr){
        if(index == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        // when we are not taking the value into the sum 
        solve(index + 1, sum, ans, arr);
        
        // when we are taking the value into sum
        sum += arr[index];
        solve(index + 1, sum, ans, arr);
        // revert the changes made to sum 
        sum -= arr[index];
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // since here we have some choices 
        // and based on those choices we ca take some decisions 
        // so we will use recursion here 
        
        
        vector<int> ans;
        int index = 0;
        int sum = 0;
        
        solve(index, sum, ans, arr);
        
        for(auto it : ans){
            if(it == target){
                return true;
            }
        }
        
        return false;
    }
};