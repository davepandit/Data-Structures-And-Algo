class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& obstacleGrid){
        if(x == 0 && y == 0){
            return 1;
        }
        if(x < 0 || y < 0){
            return 0;
        }

        // when we are moving up
        int up = obstacleGrid[x][y] == 1 ? 0 : solve(x - 1, y, obstacleGrid); // reduce x by 1 
        // when we are moving left 
        int left = obstacleGrid[x][y] == 1 ? 0 : solve(x, y - 1, obstacleGrid); // reduce y by 1

        return (up + left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int x = m - 1;
        int y = n - 1;

        return solve(x, y, obstacleGrid);
    }
};