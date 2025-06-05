class Solution {
public:
    void solve(int open, int close, string op, vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }

        // put some checks 
        if(open == close){
            // then we can only use a open bracket
            string newOp = op;
            newOp.push_back('(');
            // decrease the open brackets count 
            open = open - 1;
            solve(open, close, newOp, ans);
        }
        else if(open < close && open != 0){
            // then we need to carry out tree wala recursion
            string op1 = op; // here we will use a open bracket 
            op1.push_back('(');
        
            string op2 = op; // here we will use a close bracket 
            op2.push_back(')');

            // call for the smaller inputs 
            solve(open - 1, close, op1, ans);
            solve(open, close - 1, op2, ans); 

        }
        else if(open < close && open == 0){
            // we can only use close brackets
            string newOp = op;
            newOp.push_back(')');

            close = close - 1;
            solve(open, close, newOp, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        // since here we have some choices and based on those choices we can make 
        // some decisions, then we can use recursion here 

        vector<string> ans;
        int open = n; // this marks the no of open brackets
        int close = n; // this marks the no of close brackets\

        // here the input will be open and close  
        string op = "";
        solve(open, close, op, ans);

        return ans;
    }
};