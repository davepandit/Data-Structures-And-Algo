// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        // we will use binary search for this 
        // for that we need the range and 
        // some condition using which we can eliminate the left search space 
        // and the right search space 
        
        // sort the array 
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        
        int low = 1, high = stalls[n - 1];
        
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            
            int cowsPlaced = 1, lastCow = 0;
            for(int i = 1; i < n; ++i){
                if(stalls[i] - stalls[lastCow] >= mid){
                    // place the cow
                    lastCow = i;
                    cowsPlaced++;
                }
            }
            
            if(cowsPlaced >= k){
                // this can be out possible ans 
                ans = mid;
                // eliminate the left search space 
                low = mid + 1;
            }
            else{
                // eliminate the right search space 
                high = mid - 1;
            }
        }
        
        return ans;
        
    }
};