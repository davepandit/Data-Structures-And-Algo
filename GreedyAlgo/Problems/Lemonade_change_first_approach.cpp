class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // here we will be using greesy algo 

        vector<int> marketDeno = {20, 10, 5};

        // we need a map that will tell us how many denominations of each note do we have 
        map<int, int> mpp;
        for(int i = 0; i < marketDeno.size(); ++i){
            mpp[marketDeno[i]] = 0;
        }

        for(int i = 0; i < bills.size(); ++i){
            // increase the denomination count in the mpp
            mpp[bills[i]]++;
            int diff = bills[i] - 5;

            for(int i = 0; i < marketDeno.size(); ++i){
                int noOfDeno = diff / marketDeno[i];
                
                if(mpp[marketDeno[i]] >= noOfDeno){
                    // decrease the count of mpp[marketDeno[i]] by noOfDeno
                    mpp[marketDeno[i]] = mpp[marketDeno[i]] - noOfDeno;

                    // since we have paid some amount to the customer then the diff amount remaining 
                    // needs to be adjusted 
                    diff = diff - marketDeno[i] * noOfDeno;
                }
            }

            if(diff != 0){
                return false;
            }
        }

        // if we come here then we have served all the customers and now we return true 
        return true;
    }
};