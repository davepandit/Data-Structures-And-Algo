class Solution {
  public:
    int solve(int n, vector<int>& height){
        if(n == 0){
            return 0; // means 0 se 0 pe jaane ka cost is 0
        }
        
        int left = solve(n - 1, height) + abs(height[n] - height[n - 1]); // here we are taking one step at a time
        int right = INT_MAX;
        if(n - 2 >= 0){
            right = solve(n - 2, height) + abs(height[n] - height[n - 2]); // here we are taking 2 steps at a time
        }
        
        // since we need to return the min cost 
        return min(left, right);
    }
    
    int minCost(vector<int>& height) {
        // using the recurrence relation approach 
        // again this is not very intutive😅
        // this is similar to the climbing stairs problem 
        // so here we are trying to reach the 0th index 
        // so basically 2nd index se we can reach the 0th index
        // and the cost associated will be (height[2] - height[1]) + (height[1] - height[0])
        // if we are taking one step at a time 
        // and if we take 2 steps at a time then height[2] - height[0]
        
        int n = height.size();
        return solve(n - 1, height);
        
    }
};