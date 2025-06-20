class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        // dp[i][j] will be true if sum 'j' can be formed using first 'i' elements
        // We need totalSum + 1 columns for sums from 0 to totalSum
        // And n rows for elements from index 0 to n-1 (or n+1 rows if we consider 0 elements)
        // Let's use n rows and totalSum + 1 columns, where dp[i][j] means
        // if sum j can be achieved using elements up to index i-1.
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        // Base Case: A sum of 0 is always possible by not picking any element
        // For each element, a sum of 0 can be formed
        for(int i = 0; i < n; ++i){
            dp[i][0] = true;
        }

        // Base Case: For the first element (nums[0]), only nums[0] can be formed (if <= totalSum)
        if (nums[0] <= totalSum) { // Check to prevent out-of-bounds if nums[0] is very large
            dp[0][nums[0]] = true;
        }
        
        // Fill the DP table
        // i iterates through the elements (from the second element, index 1)
        for(int i = 1; i < n; ++i){
            // k iterates through possible sums
            for(int k = 1; k <= totalSum; ++k){
                // Option 1: Do not include the current element (nums[i])
                bool notPick = dp[i - 1][k];
                
                // Option 2: Include the current element (nums[i])
                bool pick = false;
                if(k >= nums[i]){ // Only if current sum 'k' is greater than or equal to the current element's value
                    pick = dp[i - 1][k - nums[i]];
                }
                
                dp[i][k] = pick || notPick;
            }
        }

        // After filling the DP table, find the minimum difference
        int minDiff = INT_MAX;
        // Iterate through all possible sums (s1) that can be formed using the elements
        for(int s1 = 0; s1 <= totalSum; ++s1){
            // If sum 's1' can be formed using all 'n' elements
            if(dp[n - 1][s1] == true){
                int s2 = totalSum - s1; // The other subset sum
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }

        return minDiff;
    }
};