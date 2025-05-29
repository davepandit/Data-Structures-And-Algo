class KthLargest {
private:
    int kthSmallest;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        kthSmallest = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > kthSmallest) {
                pq.pop();
            }
        }

    }
    
    int add(int val) {
        if(pq.size() < kthSmallest){
            pq.push(val);
            return pq.top();
        }
         // we need to compare the val with pq.top()
            if(val > pq.top()){
                // pop
                pq.pop();
                pq.push(val);
            }

            // now we can return the pq.top()
            return pq.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */