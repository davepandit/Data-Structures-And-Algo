class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // we will be using the concept of binary search over here 
        // first we need to define the range 
        // the range is going to be from the min to the max in the bloomDay array 
        int n = bloomDay.size();

        if(1LL * m * k > n){
            return -1;
        }

        // one O(n) pass to find out the min and the max in the bloomDay array 
        long long min = LONG_MAX, max = LONG_MIN;

        for(int i = 0; i < n; ++i){
            min = bloomDay[i] <= min ? bloomDay[i] : min;
            max = bloomDay[i] >= max ? bloomDay[i] : max;
        }

        // now we have the min and the max 
        int low = min, high = max;

        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;

            int count = 0, boquets = 0;
            for(int i = 0; i < n; ++i){
                if(bloomDay[i] <= mid){
                    count++;
                }
                else{
                    boquets += count / k;
                    count = 0;
                }
            }
            boquets += count / k;

            if(boquets >= m){
                ans = mid;
                // eliminate the right search space 
                high = mid - 1;
            }
            else if(boquets < m){
                // eliminate the left search space 
                low = mid + 1;
            }
        }

        // control will never reach here 
        return ans;
    }
};