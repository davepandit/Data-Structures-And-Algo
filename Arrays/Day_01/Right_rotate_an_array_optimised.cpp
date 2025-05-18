class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // algo 
        // reverse the whole array 
        // reverse the fist k ele 
        // reverse the next n - k ele 
        int n =  nums.size();
        k = k % n; // for k > n

        // reverse the whole array
        reverse(nums.begin(), nums.end());

        // reverse the first k ele
        reverse(nums.begin(), nums.begin() + k);
        
        // reverse the next n - k elel 
        reverse(nums.begin() + k, nums.end());
    }
};