class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < k; ++i){
            // store the last ele and shift all the ele to the right 
            int last_ele = nums[n - 1];
            // shift all the ele to the right 
            for(int i = n - 1; i > 0; --i){
                nums[i] = nums[i - 1];
            }
            // add last one to the first  
            nums[0] = last_ele;
        }
    }
};

// This is a soln having O(N*k) time complexity 