class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we will use binary search here
        // but before that we need to sort the piles array 
        sort(piles.begin(), piles.end());

        // in order to apply binary serarch we need two things->
        // 1. One is the range 
        // 2. And the other one is the elimination condition

        // one thing to note is basically the min value of k will lie in the between arr[0] to arr[n-1] after sorting 

        int n = piles.size();
        int low = 1, high = piles[n - 1];
        int k = piles[n - 1];

        while(low <= high){
            int mid = (low + high) / 2;
            long long hoursTaken = 0;
            for(int i = 0; i < n; ++i){
                hoursTaken += ceil(double(piles[i]) / mid);
            }

            if(hoursTaken <= h){
                k = mid;
                // eliminate the right search space 
                high = mid - 1;
            }
            else if(hoursTaken > h){
                // eliminate the left search space 
                low = mid + 1;
            }
        }

        return k;
    }
};