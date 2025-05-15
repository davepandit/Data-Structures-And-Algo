class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // diff kahan hai than the normal binary search 
        // here after finding the mid we need to see which part is sorted i.e the left or the right
        // note that always one of the parts will be sorted either the left one or the right one
        // then we need to ensure that whether the target ele is in the sorted part or not
        // if not then we need to go to the other part
        int low = 0, high = nums.size() - 1; 
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                // then we should trim the search space 
                low = low + 1;
                high = high - 1;
                continue;
            }
            // check if the left part is sorted or not 
            if(nums[low] <= nums[mid]){
                // then the left part is sorted 
                // yahan par aake bhi we cannot be sure that we will find the target here
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                // the right half will be sorted
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        // yahan tak pahuchna means that the ele is not found
        return false;
    }
};