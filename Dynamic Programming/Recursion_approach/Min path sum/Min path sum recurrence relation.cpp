class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& grid){
        if(x == 0 && y == 0){
            return grid[x][y];
        }
        if(x < 0 || y < 0){
            return 3000; // here i was supposed to return some large number so i used 3000 randomly
        }
            // kya karna hai + kahan jaana hai 
        int up = grid[x][y] + solve(x - 1, y, grid);
        int left = grid[x][y] + solve(x, y - 1, grid);

        // we need the min
        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // using recurrence relation 
        // in order to write recurrence we need to think kahan jaana hai + kya karna hai

        int m = grid.size();
        int n = grid[0].size();
        int x = m - 1;
        int y = n - 1;

        return solve(x, y, grid);
    }
};