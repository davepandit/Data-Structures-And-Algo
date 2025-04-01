//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // so this is some kind of dijkstras only 
        // but getting the intution that is a dijkstras problem is a bit tough 
        
        int n = 100000;
        queue<pair<int, int>> q;
        int mod = 1e5;
        // {steps, node ka val}
        vector<int> distance(n, 1e9);  // this actually stores the steps 
        distance[start] = 0;
        q.push({0, start});
        
        while(!q.empty()){
            // take out the first ele
            auto it = q.front();
            int steps = it.first;
            int node = it.second;
            
            // multiply with each of the values in array 
            for(int i = 0; i < arr.size(); ++i){
                int num = (node * arr[i]) % mod;
                
                if(steps + 1 < distance[num]){
                    // then update the distance 
                    distance[num] = steps + 1;
                    
                    if(num == end){
                        return steps + 1;
                    }
                    
                    // push the updated distance into the queue
                    q.push({distance[num], num});
                }
            }
        }
        
        // if we reach here that means we cannnot make the end value 
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends