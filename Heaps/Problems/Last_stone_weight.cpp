class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we will be using the max heap here
        // push all the stones from the array to the max heap

        int n = stones.size();
        priority_queue<int> pq;

        for(auto it : stones){
            pq.push(it);
        }

        while(pq.size() > 1){
            // we need to bring two stones with the max weight 
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x != y){
                pq.push(x - y);
            }else{
                continue;
            }
        }


        return pq.empty() ? 0 : pq.top();
    }
};