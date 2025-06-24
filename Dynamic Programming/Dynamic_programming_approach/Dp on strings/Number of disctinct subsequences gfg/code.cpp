// User function template for C++

class Solution {
  public:
    void solve(int index, string& s, string& op, set<string>& st){
        if(index == s.size()){
            st.insert(op);
            return;
        }
        
        // when we are not taking st[index]
        solve(index + 1, s, op, st);
        
        // when we are taking st[index]
        op.push_back(s[index]);
        solve(index + 1, s, op, st);
        // revert back the changes made to op
        op.pop_back();
    }
    int distinctSubsequences(string s) {
        // here we can first generate all the subsequences of the string
        // and while pushing into the final ans we can check whether that 
        // string already exists or not 
        
        int n = s.size();
        int index = 0;
        string op = "";
        set<string> st;
        
        solve(index, s, op, st);
        
        int MOD = 1e9 + 7;
        
        return st.size() % MOD;
        
    }
};