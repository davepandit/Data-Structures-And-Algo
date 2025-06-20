class Solution {
  public:
    void solve(int index, int& sum1, int& sum2, int& count, int& d, vector<int>& arr){
        if(index == arr.size()){
            if(sum1 - sum2 == d){
                count++;
            }
            
            return;
        }
        
        // when we are taking arr[index] into sum1 
        sum1 += arr[index];
        solve(index + 1, sum1, sum2, count, d, arr);
        // revert back the changes made to sum1
        sum1 -= arr[index];
        
        // when we are taking arr[index] into sum2
        sum2 += arr[index];
        solve(index + 1, sum1, sum2, count, d, arr);
        // revert back the changes made to sum2
        sum2 -= arr[index];
    }
    int countPartitions(vector<int>& arr, int d) {
        // here we have some choices and based on those choices we can take
        // some decisions so we will use recursion here 
        
        int index = 0;
        int sum1 = 0, sum2 = 0, count = 0;
        
        solve(index, sum1, sum2, count, d, arr);
        
        return count;
    }
};