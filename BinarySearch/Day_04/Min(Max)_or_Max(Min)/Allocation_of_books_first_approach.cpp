class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // brute force 
        int n = arr.size();
        
        if(k > n){
            // the no of students is greater than the no of books that we have
            return -1;
        }
        
        
        int pagesAllocated = 0, sumOfAllPages = 0;
        // this pagesAllocated will be the max in the arr 
        for(auto it : arr){
            pagesAllocated = it >= pagesAllocated ? it : pagesAllocated;
            sumOfAllPages += it;
        }
        
        
        while(pagesAllocated <= sumOfAllPages){
            int numOfStudentsAllocated = 1, maxPages = 0;
            for(int i = 0; i < n; ++i){
                if(maxPages + arr[i] > pagesAllocated){
                    // we can allocate the book to the student 
                    numOfStudentsAllocated++;
                    maxPages = arr[i];
                }
                else{
                    maxPages += arr[i];
                }
            }
            
            if(numOfStudentsAllocated <= k){
                return pagesAllocated;
            }
            else if(numOfStudentsAllocated > k){
                pagesAllocated++;
            }
        }
        
        // control will never reach here 
        return -1;
    }
};