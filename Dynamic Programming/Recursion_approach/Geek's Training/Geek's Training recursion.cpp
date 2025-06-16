class Solution {
  public:
    void solve(int index, vector<int>& op, vector<vector<int>>& arr, vector<vector<int>>& ans, vector<int>& prev){
        if(index == arr.size()){
            ans.push_back(op);
            return;
        }
        
        // i have 3 choices -> Running, Fighting, Learning 
        // if at any day i chose running then in the op i need to insert
        // arr[index][0]
        
        if(prev.empty() || prev[prev.size() - 1] != 0){
            prev.push_back(0);
            op.push_back(arr[index][0]);
            solve(index + 1, op, arr, ans, prev);
            
            // revert the changes made to op and prev
            prev.pop_back();
            op.pop_back();
        }
        
       
        
        // if at any day i chose fighting then in the op i need to insert 
        // arr[index][1]
        if(prev.empty() || prev[prev.size() - 1] != 1){
            prev.push_back(1);
            op.push_back(arr[index][1]);
            solve(index + 1, op, arr, ans, prev);
            
            // revert back the changes made to op and prev
            prev.pop_back();
            op.pop_back();
        }
        
        
        
        // if at anu day i chose learning then in the op i need to insert 
        // arr[idnex][2]
        if(prev.empty() || prev[prev.size() - 1] != 2){
            prev.push_back(2);
            op.push_back(arr[index][2]);
            solve(index + 1, op, arr, ans, prev);
            
            // revert back the changes made to op and prev
            prev.pop_back();
            op.pop_back();
        }
        
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // since here we have some choices and based on those choices we 
        // can take some decisions so here we can use recursion 
        
        
        vector<int> op;
        vector<vector<int>> ans;
        vector<int> prev; // this will be used to keep a track that we are not 
        // doing the same in 2 consecutive days
        
        solve(0, op, arr, ans, prev);
        
        int res = INT_MIN;
        for(auto p : ans){
            int sum = 0;
            for(auto q : p){
                sum += q;
            }
            
            res = sum > res ? sum : res;
        }
        
        return res;
        
    }
};