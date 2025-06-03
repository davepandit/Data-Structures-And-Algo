class Solution {
public:
    bool canJump(vector<int>& nums) {
        // here also we will be using the greedy algo 
        int maxIndex = 0;

        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i > maxIndex){
                return false;
            }

            // take the max jump 
            maxIndex = max(maxIndex, nums[i] + i);
        }

        // if we reach here then we can return true
        return true;
    }
};