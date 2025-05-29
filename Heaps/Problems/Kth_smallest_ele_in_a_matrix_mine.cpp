class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // we will use a min heap here 
        priority_queue<int, vector<int>, greater<int>> pq;
        // insert first k ele into the pq 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                pq.push(matrix[i][j]);
            }
        }

        int count = 0;
        while(!pq.empty()){
            if(count == k - 1){
                break;
            }
            pq.pop();
            count = count + 1;
        }

        return pq.top();
    }
};