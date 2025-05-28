class Solution {
  public:
    int minCost(vector<int>& arr) {
        // here also we will be using the priority queue(min heap)
        priority_queue<int, vector<int>, greater<int>> pq;
        int minCost = 0;
        
        // first we will insert all the ele of the array into a pq
        for(auto it : arr){
            pq.push(it);
        }
        
        // no we need to take the two min ele and add them to the cost and put their
        // sum in the arr
        
        while(pq.size() > 1){
            int val = 0;
            // the below loop is to add the two min ele 
            for(int i = 0; i < 2; ++i){
                if(!pq.empty()){
                    val += pq.top();
                    pq.pop();
                }
            }
            
            // add the val to the cost 
            minCost += val;
            pq.push(val);
        }
        
        return minCost;
    }
};