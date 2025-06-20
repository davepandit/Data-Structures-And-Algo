class Solution {
  public:  
    int solve(int index, int& sum, int& target, int& count, vector<int>& arr){
        if(index < 0){
            if(sum == target){
                count++;
            }
            
            return count;
        }
        
        // when we are not taking arr[index] into sum
        int left = solve(index - 1, sum, target, count, arr);
        
        // when we are taking arr[index] into sum
        sum += arr[index];
        int right = solve(index - 1, sum, target, count, arr);
        // revert back the changes made to sum 
        sum -= arr[index];
        
        return count;
    }
    int perfectSum(vector<int>& arr, int target) {
        // using recurrence relation 
        
        int n = arr.size();
        int index = n - 1, sum = 0, count = 0;
        
        return solve(index, sum, target, count, arr);
    }
};