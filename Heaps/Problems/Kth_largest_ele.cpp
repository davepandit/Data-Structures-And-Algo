class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // this can be easily solved using the priority queue
        // note one imp thing : if we need to find the largest ele then we should 
        // use a min heap and if we want to find the smallest ele then we should be 
        // using a max heap
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();

        // insert the first k ele 
        for(int i = 0; i < k; ++i){
            pq.push(nums[i]);
        }

        // now we can check for the other n-k ele in the array 
        // if we find any ele larger than the top then we can insert that 
        for(int i = k; i < n; ++i){
            int top_ele = pq.top();
            if(nums[i] > top_ele){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // the top wala ele is the answer 
        return pq.top();
    }
};