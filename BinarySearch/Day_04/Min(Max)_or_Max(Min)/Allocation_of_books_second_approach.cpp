class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // we will be solving this problem using the binary search 
        // for that we need two things 
        // one is the range
        // and the other one is a condition on how can we eliminate the search spaces 
        
        int n = arr.size();
        
        if(k > n){
            // the no of students is greater than the no of books that we have
            return -1;
        }
        
        
        int low = 0, high = 0;
        
        for(auto it : arr){
            low = it >= low ? it : low;
            high += it;
        }
        
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            
            int numOfStudentsAllocated = 1, maxPages = 0;
            for(int i = 0; i < n; ++i){
                if(maxPages + arr[i] > mid){
                    // we can allocate the book to the student 
                    numOfStudentsAllocated++;
                    maxPages = arr[i];
                }
                else{
                    maxPages += arr[i];
                }
            }
            
            if(numOfStudentsAllocated <= k){
                // this can be our possible ans 
                ans = mid;
                // eliminate the right search space 
                high = mid - 1;
            }
            else if(numOfStudentsAllocated > k){
                // eliminate the left search space 
                low = mid + 1;
            }
        }
        
        // control will never reach here 
        return ans;
    }
};