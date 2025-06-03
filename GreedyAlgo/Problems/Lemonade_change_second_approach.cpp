class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // we will use greedy here 
        // this is more of a common sense problem 
        // the only thing that is greedy here is chutta dete samay we first need to give the customer 
        // a higher denomination then a smaller one 

        int five = 0;
        int ten = 0;

        for(int i = 0; i < bills.size(); ++i){
            if(bills[i] == 5){
                // we need not return any paisa to the customer back 
                // simply increase the count 
                five += 1;
            }
            else if(bills[i] == 10){
                // we need to return one 5 
                if(five){
                    ten += 1;
                    five -= 1;
                }else{
                    return false;
                }
            }
            else{
                // we need to return 10 and 5 to the customer 
                // if not there then we can return three 5's

                if(ten && five){
                    ten -= 1;
                    five -= 1;
                }

                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }

        // if we reach here that means we can serve all the customers 
        return true;
    }
};