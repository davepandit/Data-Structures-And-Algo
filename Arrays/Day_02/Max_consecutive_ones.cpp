class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // this can be solved using two pointers 
        int max = 0;
        int low = -1, high = -1;
        for(int i = 0; i < nums.size(); ++i){
            if((low == -1 && high == -1) && nums[i] == 1){
                low = i;
                high = i;
            }
            else if(nums[i] == 1){
                high = high + 1;
            }
            else if(nums[i] != 1 && low != -1){
                max = high - low + 1 > max ? high - low + 1 : max;
                low = -1;
                high = -1;
            }
        }
        if(low == -1 && max == 0){
            return 0;
        }
        return high - low + 1 > max ? high - low + 1 : max;
    }
};

// this is a very very bad solution 