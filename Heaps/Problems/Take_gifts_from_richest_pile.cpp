class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // here also we will be using a max heap 
        int n = gifts.size();
        priority_queue<int> pq;

        // insert all the ele from the arr to the max heap
        for(auto it : gifts){
            pq.push(it);
        }

        long long giftsRemaining = 0;
        while(k > 0){
            // take out the top from the max heap 
            int gift = pq.top();
            pq.pop();

            pq.push(floor(sqrt(gift)));

            k = k - 1;
        }

        while(!pq.empty()){
            // take out the ele 
            giftsRemaining += pq.top();
            pq.pop();
        }

        return giftsRemaining;
    }
};