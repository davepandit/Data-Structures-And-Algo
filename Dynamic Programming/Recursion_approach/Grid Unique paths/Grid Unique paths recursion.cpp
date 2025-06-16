class Solution {
public:
    void solve(int x, int y, int& m, int& n, int& noOfWays, vector<pair<int, int>>& directions){
        if(x == m - 1 && y == n - 1){
            noOfWays++;
            return;
        }

        for(auto [di, dj] : directions){
            int ni = x + di;
            int nj = y + dj;

            if(ni < m && nj < n){
                // when we take down 
                solve(ni, nj, m, n, noOfWays, directions);
            }
        }
    }
    int uniquePaths(int m, int n) {
        // since here we have some choices and based on those choices we can take some 
        // decisions so we will use recursion here 

        int noOfWays = 0;
        int x = 0, y = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}}; // this contains down, right directions
        solve(x, y, m, n, noOfWays, directions);

        return noOfWays;
    }
};