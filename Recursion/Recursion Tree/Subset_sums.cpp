class Solution {
  public:
    void solve(vector<int> ip, vector<int> op, vector<int>& ans){
        if(ip.size() == 0){
            int sum = 0;
            for(int it : op){
                sum += it;
            }
            
            // push back the sum into the ans
            ans.push_back(sum);
            return;
        }
        
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
    
        // make the ip smaller 
        ip.erase(ip.begin());
        
        // call for the function again 
        solve(ip, op1, ans);
        solve(ip, op2, ans);
        
    }
    
   
    vector<int> subsetSums(vector<int>& arr) {
        // in this problem we have some choices 
        // and based on those choices we can take some decisions
        // so here we will use recursion
        
        vector<int> op;
        vector<int> ans;
        
        solve(arr, op, ans);
        
        // sort the array 
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};