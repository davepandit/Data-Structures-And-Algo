class Solution {
public:
    void solve(string ip, string op, vector<string>& ans){
        if(ip.length() == 0){
            ans.push_back(op);
            return;
        }

        // check whether the first char in the ip is a digit or not 
        if(ip[0] >= '0' && ip[0] <= '9'){
            // then it is a digit 
            // no need to make two diff function calls 
            string newOp = op + ip[0];
            // make the input smaller 
            ip.erase(ip.begin() + 0);
            solve(ip, newOp, ans);
        }
        else{
            // here we need to do tree wala recursion 
            string op1 = op; // here we will change the case 
            op1.push_back(ip[0]);

            string op2 = op; // here we will change the case 
            (int)ip[0] >= 65 && (int)ip[0] <= 90 ? op2.push_back(ip[0] + 32): op2.push_back(ip[0] - 32);

            // make the ip smaller 
            ip.erase(ip.begin() + 0);
            // call for the smaller inputs 
            solve(ip, op1, ans);
            solve(ip, op2, ans);

        }
    }
    vector<string> letterCasePermutation(string s) {
        // since on seeing this problem we can see there are some choices 
        // and based on those choices we can take decisions 
        // so recursion to use hone wala hai 

        string ip = s;
        string op = "";

        vector<string> ans;

        solve(ip, op, ans);
        return ans;
    }
};