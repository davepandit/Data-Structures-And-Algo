// User function template for C++
class Solution {
  public:
    int solve(int index, vector<int>& arr){
        if(index == 0){
            return arr[index];
        }
        if(index < 0){
            return 0;
        }
        
        // if we are picking an ele
        int pick = arr[index] + solve(index - 2, arr);
        
        // if we are not picking an ele 
        int notPick = 0 + solve(index - 1, arr);
        
        // now we need to return the max 
        return max(pick, notPick);
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // again this is not very intutive at the first sight 
        // but kind of following the same pattern 
        // as the frog jump and the climbing stairs
        // one very imp thing to note in this problem is like we are 
        // always starting from the back 
        
        int n = arr.size();
        return solve(n - 1, arr);
    }
};