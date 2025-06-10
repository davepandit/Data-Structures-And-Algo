

class Solution {
  public:
    void solve(int index, string& s, int k, vector<string>& ans){
        if(k == 0 || index == s.size()){
            ans.push_back(s);
            return;
        }
        
        int max = index; // this is the index not the actual value
        for(int i = index + 1; i < s.size(); ++i){
            max = s[i] > s[max] ? i : max;
        }
        
        // now we have got the index where the val is max 
        char maxi = s[max];
        
        if(maxi == s[index]){
            solve(index + 1, s, k, ans);
        }
        else{
            for(int i = index + 1; i < s.size(); ++i){
                if(s[i] == maxi){
                    swap(s[index], s[i]);
                    // call the function again 
                    solve(index + 1, s, k - 1, ans);
                    // revert the changes on the string 
                    swap(s[index], s[i]);
                }
            }
        }
        
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // here we have choices and based on those choices we can take some 
        // decisions and hence this is a recursion wala problem 
        // on analysing more we can see that there is some control 
        // that we can do on recursion and hence this is a backtracking problem 
        
        vector<string> ans;
        int index = 0;
        solve(index, s, k, ans);
        
        // iterate over ans to find the max number 
        sort(ans.begin(), ans.end(), greater<string>());
        
        return ans[0];
    }
};