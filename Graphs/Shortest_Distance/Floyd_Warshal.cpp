//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& matrix) {
        // algorithm 
        // 1. Here we will be using the floyd warshal algo
        
        int n = matrix.size();   
        const int INF = 1e9;
        
        // Step 1: Convert -1 to INF (except diagonal elements)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = INF;
                }
            }
        }
        
        
        for(int via = 0; via < n; ++via){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                   if (matrix[i][via] != INF && matrix[via][j] != INF) {
                       matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                   }
                }
            }
        }
        
        // Step 3: Convert INF back to -1 (for unreachable nodes)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == INF) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends