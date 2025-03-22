#include <bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>>& visited, vector<vector<char>>& board){
    // mark the source ele 
    int n = board.size();
    int m = board[0].size();
    visited[sr][sc] = 1;

    // make the vector which will allow to travel up, down, left and right maybe
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for(auto [di, dj] : directions){
        int ni = sr + di;
        int nj = sc + dj;

        if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O' && visited[ni][nj] == 0){
            // then we need to call the dfs from here again
            dfs(ni, nj, visited, board);
        }
    }

}

void solve(vector<vector<char>>& board){
    // get the no of rows 
    int m = board.size();
    // get the no of cols
    int n = board[0].size();

    vector<vector<int>> visited(m, vector<int> (n, 0));

    // traverse through the boundary of the matrix and see if there are some Os 
    // if there are then call dfs with that O ka position 
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O'){
                // call the dfs for that and send the visited along with that
                if(visited[i][j] == 0){
                    dfs(i, j, visited, board);
                }
            }
        }
    }

    //  till now we have the visited matrix sorted 
    // basically in the visited matrix jahan jahan pe we have 1 we need to get those indexes
    // and those are the indexes jahan pe we need to keep the Os as it is 
    // and replace all the other Os with X
    for(int i = 0; i < visited.size(); ++i){
        for(int j = 0; j < visited[0].size(); ++j){
            if(visited[i][j] != 1 && board[i][j] == 'O'){
                // then we can reeplace that O with X
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    // say we have the adj matrix so basically we are calling the solve function with that
    vector<vector<char>> board;
    solve(board);
    return 0;
}