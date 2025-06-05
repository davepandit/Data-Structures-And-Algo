/*You are required to complete this method */

class Solution {
  public:
    void solve(int start, int k, vector<int>& ans){
        if(ans.size() == 1){
            return;
        }
        
        int posToBeDeleted = (start + k - 1) % ans.size();
        ans.erase(ans.begin() + posToBeDeleted);
        
        // call for the function again with smaller input 
        solve(posToBeDeleted, k, ans);
    }
    int josephus(int n, int k) {
        // using IBH method
        
        int start = 0;
        int person = 1;
        // make an array
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            ans[i] = person;
            
            person = person + 1;
        }
        
        // say n = 5
        // ans = [1, 2, 3, 4, 5];
        
        solve(start, k, ans);
        
        return ans[0];
        
    }
};