// User function Template for C++

class Solution {
  public:
    void solve(int index, string& ip, string& op, vector<string>& ans){
        if(index == ip.size()){
            ans.push_back(op);
            return;
        }
        
        // when we are not taking ans[index] 
        solve(index + 1, ip, op, ans);
        
        // when we are taking ans[index]
        op.push_back(ip[index]);
        solve(index + 1, ip, op, ans);
        // revert back the changes made to op
        op.pop_back();
        
    }
    bool isPallindrome(string& text){
        int low = 0, high = text.size() - 1;
        while(low <= high){
            if(text[low] == text[high]){
                low = low + 1;
                high = high - 1;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int longestPalinSubseq(string &s) {
        // since here we have some choices and 
        // based on the choices we can take some decisions 
        // so we will use recursion here 
        
        int n = s.size(), index = 0;
        string op = "";
        vector<string> ans;
        
        solve(index, s, op, ans);
        
        int res = 0;
        for(string it : ans){
            if(isPallindrome(it)){
                res = it.size() > res ? it.size() : res;
            }
        }
        
        
        return res;
        
    }
};