class Solution {
public:
    void solve(int ip, int op, int& noOfWays){
        if(op == ip){
            noOfWays++;
            return;
        }
        else if(op > ip){
            return;
        }

        solve(ip, op + 1, noOfWays); // taking one step at a time 
        solve(ip, op + 2, noOfWays); // taking 2 steps at a time 
    }
    int climbStairs(int n) {
        // since here we have some choices and based on those choices we can take some decisions so we will use recursion here 

        int noOfWays = 0;
        int op = 0;
        solve(n, op, noOfWays);

        return noOfWays;
    }
};