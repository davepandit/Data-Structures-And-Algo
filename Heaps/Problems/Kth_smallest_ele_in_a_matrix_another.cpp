class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // we can solve this problem in O(klogn + n) time complexity 
        // this is the 3rd method discussed in the video https://www.youtube.com/watch?v=WfTCdP8kBWQ&list=PLQEaRBV9gAFtRabbmFxqeI6wa50L9EgcF&index=6

        // push all the ele in a column to a min heap(priority queue)
        // pop out the ele from the pq and the ele popped out wo jis row me tha uske next 
        // ele koi daal do 

        int n = matrix.size();

        // now we can make a heap from the array in O(log n) time 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for(int i = 0; i < n; ++i){
            pq.push({matrix[i][0], {i, 0}});
        }

        int count = 0;
        int kthsmallest;
        while(!pq.empty()){
            auto ele = pq.top();
            kthsmallest = ele.first;
            int x = ele.second.first;
            int y = ele.second.second;

            pq.pop();

            if(x < n && y + 1 < n){
                pq.push({matrix[x][y + 1], {x, y + 1}});
            }

            count++;
            if(count == k){
                break;
            }

        }

        return kthsmallest;
    }
};