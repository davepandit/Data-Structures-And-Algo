class Solution {
public:
    void solve(int x, int y, int& m, int& n, int& sum, vector<vector<int>>& triangle, vector<int>& ans){
        if(x == m - 1){
            sum += triangle[x][y];
            ans.push_back(sum);
            // revert back the changes made to sum 
            sum -= triangle[x][y];
            return;
        }

        // if we go to i
        if(x + 1 < m && y < n){
            sum += triangle[x][y];
            solve(x + 1, y, m, n, sum, triangle, ans);
            // revert back the changes 
            sum -= triangle[x][y];
        }
        
        if(x + 1 < m && y + 1 < n){
            sum += triangle[x][y];
            solve(x + 1, y + 1, m, n, sum, triangle, ans);
            // revert back the changes 
            sum -= triangle[x][y];
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // since here we have some choices and based on those choices we can take some 
        // decisions so we can use recurion


        int m = triangle.size();
        int n = triangle[m - 1].size();
        int x = 0, y = 0;
        vector<int> ans;
        int sum = 0;

        solve(x, y, m, n, sum, triangle, ans);

        sort(ans.begin(), ans.end());

        return ans[0];
    }
};