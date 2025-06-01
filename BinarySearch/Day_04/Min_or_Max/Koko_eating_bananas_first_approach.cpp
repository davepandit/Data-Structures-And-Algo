class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        while(true){
            long long hours = 0;
            for(int i = 0; i < piles.size(); ++i){
                hours += ceil(double(piles[i]) / k);
            }

            if(hours <= h){
                // then we have got the min k value 
                return k;
            }

            k++;
        }
    }
};