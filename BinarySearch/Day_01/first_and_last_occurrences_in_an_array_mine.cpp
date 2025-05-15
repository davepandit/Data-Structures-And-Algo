class Solution {
public:
    void helper(vector<int>& nums, int low, int high, int target, int& first_occ, int& last_occ){
        // base case 
        if(low > high){
            return;
        }
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            first_occ = (mid < first_occ) ? mid : first_occ;
            last_occ = (mid > last_occ) ? mid : last_occ;
            // we need to search for more possible first occurences in the first half 
            // that is from low to mid - 1
            helper(nums, low, mid - 1, target, first_occ, last_occ);
            // we need to search for more possible last occurences in the second half
            // that is from mid + 1 to high
            helper(nums, mid + 1, high, target, first_occ, last_occ);
        }
        else if(nums[mid] > target){
            helper(nums, low, mid - 1, target, first_occ, last_occ);
        }
        else{
            helper(nums, mid + 1, high, target, first_occ, last_occ);
        }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // we will use recursion to solve this 
        // we need to make a helper function for this 
        int low = 0, high = nums.size() - 1;
        vector<int> ans = {-1, -1};
        int first_occ = nums.size() + 1, last_occ = -1;
        // this helper function will return the array
        helper(nums, low, high, target, first_occ, last_occ);
        if(first_occ == nums.size() + 1 && last_occ == -1){
            return ans;
        }
        // now the first occurence and the last occurence contain the correct value
        ans[0] = first_occ;
        ans[1] = last_occ;

        return ans;
    }
};