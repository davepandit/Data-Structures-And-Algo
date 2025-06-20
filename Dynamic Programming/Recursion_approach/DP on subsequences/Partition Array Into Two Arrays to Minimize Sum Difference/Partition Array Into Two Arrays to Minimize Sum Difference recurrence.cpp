class Solution {
public:
    int solve(int index, int& sum1, int& sum2, int& size1, int& size2, vector<int>& nums){
        if(index < 0){
            return abs(sum1 - sum2);
        }


        int left = INT_MAX, right = INT_MAX;
        // when we are taking nums[index] into sum1 
        if(size1 < nums.size() / 2){
            sum1 += nums[index];
            size1++;
            left = solve(index - 1, sum1, sum2, size1, size2, nums);
            // revert back the changes made to sum1 and size 1
            size1--;
            sum1 -= nums[index];
        }

        if(size2 < nums.size() / 2){
            sum2 += nums[index];
            size2++;
            right = solve(index - 1, sum1, sum2, size1, size2, nums);
            size2--;
            sum2 -= nums[index];
        }

        return min(left, right);
        
    }
    int minimumDifference(vector<int>& nums) {
        // using recurrence relation 
        // kya karna hai + kahan jaana hai 

        int n = nums.size();
        int index = n - 1;
        int sum1 = 0, sum2 = 0, size1 = 0, size2 = 0;

        return solve(index, sum1, sum2, size1, size2, nums);
    }
};