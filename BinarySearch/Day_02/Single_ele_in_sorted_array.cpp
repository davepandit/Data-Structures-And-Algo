class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // this is a very interesting problem 
        // in binary search we always need to eliminate some half 
        // here how can we eliminate a half 
        // (even, odd) -> then we need to eliminate the left half
        // the above statement means that if the pair is in the (even, odd) indexes then we need
        // to eliminate the left half
        // (odd, even) -> then we need to eliminate the right half
        // this logic comes from 😅😅
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n - 1] != nums[n - 2]){
            return nums[n - 1];
        }

        // now we can start with the typical binary search 
        int low = 1, high = n - 2;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            // (odd, even) pair
            if(nums[mid - 1] == nums[mid] && mid % 2 == 0){
                // then eliminate the right part 
                high = mid - 1;
            }
            // (even, odd) pair
            else if(nums[mid - 1] == nums[mid] && mid % 2 != 0){
                // then eliminate the left part 
                low = mid + 1;
            }
            // (even, odd) pair
            else if(nums[mid + 1] == nums[mid] && mid % 2 == 0){
                // then eliminate the left part 
                low = mid + 1;
            }
            // (even, odd) pair
            else if(nums[mid + 1] == nums[mid] && mid % 2 != 0){
                // then eliminate the right part 
                high = mid - 1;
            }
        }
        return -1;
    }
};