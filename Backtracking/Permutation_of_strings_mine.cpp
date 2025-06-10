class Solution {
  public:
    void solve(string& s, vector<string>& ans){
        for(int i = 0; i < s.size(); ++i){
            swap(s[0], s[i]);
            if(find(ans.begin(), ans.end(), s) == ans.end()){
                // the string is not there in the set 
                ans.push_back(s);
                solve(s, ans);
            }
            
            // since we are passing by reference so we need to revert the changes
            swap(s[0], s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // here we have some choices and based on those 
        // choices we can take soeme decisions so 
        // we can use recursion here, but here also recursive 
        // tree banane ke baad we can see that backtracking can 
        // also be used here 
        
        // hence we will use backtracking 
        
        vector<string> ans;
        ans.push_back(s);
        solve(s, ans);
        
        return ans;
    }
};
