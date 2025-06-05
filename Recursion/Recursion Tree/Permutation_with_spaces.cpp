class Solution {
  public:
    void solve(string ip,string op, vector<string>& ans){
        if(ip.length() == 0){
            ans.push_back(op);
            return;
        }
        
        // take ip[0] without a space 
        string op1 = op + ip[0];
        string op2 = op + " " + ip[0];
        
        // make the input smaller 
        ip.erase(ip.begin() + 0);
        
        // call for the recursive halfs 
        solve(ip, op1, ans);
        solve(ip, op2, ans);
    }
    vector<string> permutation(string s) {
        // since in this problem we have some choices to make 
        // and we can take decisions based on choices that we have 
        // so this is a recursive problem
        
        vector<string> ans;
        string op = "";
        
        // we know that we dont have any choice for the first letter 
        // in the string 
        
        // so that anyhow needs to be there in the op as it is 
        // means uske age we cannot use a space right 
        // we cannot take something as _A(assuming that the string starts with A)
        op.push_back(s[0]);
        
        // also we need to make the input a bit smaller 
        s.erase(s.begin() + 0);
        
        // now we can all the recursive function
        solve(s, op, ans);
        
        // i think we need to sort the array before returning the ans 
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};