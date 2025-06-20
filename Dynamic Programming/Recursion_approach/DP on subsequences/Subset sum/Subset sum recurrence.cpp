class Solution {
  public:
    bool solve(int index, int target, vector<int>& arr){
        if(target == 0){
            return true;
        }
        else if(index == 0 && arr[index] == target){
            return true;
        }
        else if(index == 0 && arr[index] != target){
            return false;
        }
        
        // when we dont include that arr[index] into the ans 
        bool notPick = solve(index - 1, target, arr);
        
        // when we include that arr[index] into the ans 
        bool pick = solve(index - 1, target - arr[index], arr);
        
        return (pick || notPick);
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // using recurrence relation 
        // kya karna hai + kahan jaana hai 
        
        int index = arr.size() - 1;
        
        return solve(index, target, arr);
    }
};