class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        // base case when m * k is greater than the no of flowers that can bloom even at the last day
        int n = bloomDay.size();
        if(m * k > n){
            return -1;
        }

        // one pass to find the min and the max in the bloomDay 
        // because the answer will lie in the between the min to the max
        long long min = LONG_MAX, max = LONG_MIN;

        for(int i = 0; i < n; ++i){
            min = bloomDay[i] <= min ? bloomDay[i] : min;
            max = bloomDay[i] >= max ? bloomDay[i] : max;
        }

        // now we have the min and the max
        int day = min;

        while(day <= max){
            int count = 0, boquets = 0;
            for(int i = 0; i < n; ++i){
                if(bloomDay[i] <= day){
                    count++;
                }
                else{
                    boquets += count / k;
                    count = 0;
                }
            }
            boquets += count / k;
            if(boquets >= m){
                return day;
            }

            // increase the day and go again 
            day++;
        }

        // control will never reach here 
        return -1;
    }
};