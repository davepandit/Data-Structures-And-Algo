class Solution {
  public:
    void solve(string ip, string op, vector<string>& ans){
        if(ip.size() == 0){
            ans.push_back(op);
            return;
        }
        
        string op1 = op; // here we will not take ip[0]
        string op2 = op; // here we will take ip[0]
        op2.push_back(ip[0]);
        
        // make the ip smaller 
        ip.erase(ip.begin());
        
        // call the function again 
        solve(ip, op1, ans);
        solve(ip, op2, ans);
    }
    vector<string> AllPossibleStrings(string s) {
        // here we have choices and based on those choices 
        // we can take some decisions 
        // so here we can use the recunsion tree method 
        
        vector<string> ans;
        string ip = s;
        string op = "";
        
        solve(ip, op, ans);
        
        // ans ka first index will always be an empty string 
        // because the way we have designed the recursion is that only 
        ans.erase(ans.begin());
        
        // now we need to sort the array 
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};