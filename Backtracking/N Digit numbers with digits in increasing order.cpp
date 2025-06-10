// User function Template for C++
class Solution {
  public:
    void solve(int index, string& op, vector<int>& ans, int n){
        if(op.size() == n){
            // convert the op into int
            ans.push_back(stoi(op));
            return;
        }
        
        for(int i = index; i <= 9; ++i){
            op.push_back(i + '0');
            
            // call for the function 
            solve(i + 1, op, ans, n);
            
            // revert the op changes 
            op.pop_back();
        }
        
    }
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        if(n == 1){
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        
        
        int index = 1;
        string op = "";
        vector<int> ans;
        
        solve(index, op, ans, n);
        
        return ans;
    }
};