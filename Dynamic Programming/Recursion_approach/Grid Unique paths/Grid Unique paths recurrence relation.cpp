class Solution {
public:
    int solve(int x, int y){
        if(x == 0 && y == 0){
            return 1;
        }
        if(x < 0 || y < 0){
            return 0;
        }

        // when we are moving up
        int up = solve(x - 1, y); // reduce x by 1 
        // when we are moving left 
        int left = solve(x, y - 1); // reduce y by 1

        return (up + left);
    }
    int uniquePaths(int m, int n) {
        // using recurrence relaion 


        int x = m - 1;
        int y = n - 1;

        return solve(x, y);
    }
};