class Solution {
  public:
    void solve(int index, int& sum, int& count, int& target, vector<int>& arr){
        if(index == arr.size()){
            if(sum == target){
                count++;
            }
            
            return;
        }
        
        // when we are not taking arr[index] into sum
        solve(index + 1, sum, count, target, arr);
        
        // when we are taking arr[index] into sum 
        sum += arr[index];
        solve(index + 1, sum, count, target, arr);
        // revert back the changes made to sum
        sum -= arr[index];
    }
    int perfectSum(vector<int>& arr, int target) {
        // since here we have some choices and based on those choices 
        // we can take some decisions so we will use recursion here
        
        int n = arr.size();
        int index = 0;
        int sum = 0;
        int count = 0;
        
        solve(index, sum, count, target, arr);
        
        return count;
    }
};