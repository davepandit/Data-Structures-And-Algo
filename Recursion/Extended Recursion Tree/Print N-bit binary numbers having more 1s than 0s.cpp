// User function template for C++
class Solution {
  public:
    void solve(int zeroes, int ones,string op, vector<string>& ans,int n){
        if(zeroes + ones == n){
            ans.push_back(op);
            return;
        }
        
        if(zeroes == ones){
            // then we have only one option that is to include one 1
            string newOp = op;
            newOp.push_back('1');
            ones = ones + 1;
            solve(zeroes, ones, newOp, ans, n);
        }
        
        else if(ones > zeroes){
            // then we can make the tree wala recursion 
            string op1 = op; // here we will take a zero 
            op1.push_back('0');
            
            string op2 = op; // here we will take a one
            op2.push_back('1');
            
            solve(zeroes + 1, ones, op1, ans, n);
            solve(zeroes, ones + 1, op2, ans, n);
        }
    }
    vector<string> NBitBinary(int n) {
        // here we can see that we have some choices and based on those 
        // choices we can make some decisions so this is a problem of 
        // recursion 
        
        int zeroes = 0;
        int ones = 0;
        
        string op = "";
        
        vector<string> ans;
        solve(zeroes, ones,op, ans, n);
        
        // here we need to sort the array 
        sort(ans.begin(), ans.end(), greater<string>());
        return ans;
    }
};