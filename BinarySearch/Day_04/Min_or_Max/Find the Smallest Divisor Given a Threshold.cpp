class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // we will solve this using binary serach 
        // again we need two imp things one is range, and how can we eliminate the search spaces 

        // the range is from the min ele to the max ele in the nums array 
        int n = nums.size();

        long long max = LONG_MIN;
        for(int i = 0; i < n; ++i){
            max = nums[i] >= max ? nums[i] : max;
        }

        // now we have the min and the max 
        int low = 1, high = max;

        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;

            int sum = 0;
            for(int i = 0; i < n; ++i){
                sum += ceil(double(nums[i]) / mid);
            }

            if(sum <= threshold){
                ans = mid;
                // eliminate the right search space 
                high = mid - 1;
            }
            else if(sum > threshold){
                // eliminate the left search space 
                low = mid + 1;
            }
        }


        return ans;
    }
};