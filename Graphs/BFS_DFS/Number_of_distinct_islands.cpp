#include <bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>>& visited){
    int n = grid.size();
    int m = grid[0].size();

    visited[sr][sc] = 1;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for(auto [di, dj] : directions){
        int ni = sr + di;
        int nj = sc + dj;

        // now check whether at grid[ni][nj] == 1, if it is then we can call the dfs again provided that grid[ni][nj] is not visited yet 
        if((ni >= 0 && ni < m && nj >= 0 && nj < n) && grid[ni][nj] == 1 && visited[ni][nj] == 0){
            // then we can call for the dfs again
            dfs(ni, nj, grid, visited);
        }
    }

    
}

int no_of_islands(vector<vector<int>> grid){
    // grid here is the matrix that is given to us
    // we will be solving this using the dfs approach 
    // make one visited matrix that will mark the position of 1s as 0 and other positions with some INT_MAX
    // after we have created a matrix of this type then we can call for the dfs function 

    // from this function how many times the dfs is called that is the number of unique islands
    // and hence the ans 
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int> (m, 0));
    int counter = 0;

    // Iterate over the grid and call DFS when an unvisited 1 is found
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 1 && visited[i][j] == 0) {
                counter += 1;
                dfs(i, j, grid, visited);
            }
        }
    }

    // we can return counter 
    return counter;
}

int main(){
    // consider that we are given the matrix 
    vector<vector<int>> grid;
    int ans = no_of_islands(grid);
    cout << "The number of distinct islands is:" << ans;
    return 0;
}