class Solution {
public:
    int rob(vector<int>& nums) {
        // this is the tabulation method 
        if (nums.size() == 1) return nums[0];
        
        // remove the first ele 
        int first = nums[0];
        nums.erase(nums.begin() + 0);
        int n = nums.size();
        vector<int> dp1(n, -1);

        dp1[0] = nums[0];
        int negative = 0;

        for(int i = 1; i < n; ++i){
            int rob = nums[i] + ((i - 2 < 0) ? negative : dp1[i - 2]);
            int notRob = 0 + dp1[i - 1];

            dp1[i] = max(rob, notRob);
        }

        // now we can remove the last ele and do the same thing
        // but we need to insert the first ele at the correct position 
        nums.insert(nums.begin() + 0, first);
        nums.erase(nums.begin() + nums.size() - 1);

        n = nums.size();
        vector<int> dp2(n, -1);
        
        dp2[0] = nums[0];
        for(int i = 1; i < n; ++i){
            int rob = nums[i] + ((i - 2 < 0) ? negative : dp2[i - 2]);
            int notRob = 0 + dp2[i - 1];

            dp2[i] = max(rob, notRob);
        } 


        return max(dp1[n - 1], dp2[n - 1]);
    }
};