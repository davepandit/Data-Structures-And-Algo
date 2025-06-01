// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        // brute force
        // sort the stalls array 
        sort(stalls.begin(), stalls.end());
        
        int minDis = 1;
        int ans = 0;
        int maxDis = stalls.back() - stalls.front(); 

        while (minDis <= maxDis) {
            int cowsPlaced = 1;
            int lastCow = 0;

            for (int i = 1; i < stalls.size(); ++i) {
                if (stalls[i] - stalls[lastCow] >= minDis) {
                    lastCow = i;
                    cowsPlaced++;
                }
            }

            if (cowsPlaced >= k) {
                ans = minDis;      
                minDis++;        
            } else {
                break;             
            }
        }

        return ans;
        
        
    }
};