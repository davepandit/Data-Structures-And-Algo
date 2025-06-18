class Solution {
public:
    void solve(int x, int y, int& m, int& n, int& sum, vector<int>& ans, vector<vector<int>>& grid, vector<pair<int, int>>& directions){
        if(x == m - 1 && y == n - 1){
            sum += grid[x][y];
            ans.push_back(sum);
            sum -= grid[x][y];
            return;
        }

        for(auto [di, dj] : directions){
            int ni = x + di;
            int nj = y + dj;

            if(ni < m && nj < n){
                sum += grid[x][y];

                solve(ni, nj, m, n, sum, ans, grid, directions);

                // revert back the changes made to sum 
                sum -= grid[x][y];
            }
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        // since here we have some choices and based on those 
        // choices we can take some decisions so we will use recursion here 

        int m = grid.size();
        int n = grid[0].size();

        int x = 0, y = 0;
        vector<int> ans;
        int sum = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}}; // this is the down and the right direction 

        solve(x, y, m, n, sum, ans, grid, directions);

        sort(ans.begin(), ans.end());
        return ans[0];
    }
};