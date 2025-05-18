//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // The crux of the problem is the ans is the position of the min ele in the array 
        // the ultimate aim is to find out the min ele in the array 
        int n = arr.size();
        int low = 0, high = n - 1;
        int min = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            // check which part is sorted 
            if(arr[low] <= arr[mid]){
                // then the left part is sorted
                min = arr[low] <= min ? arr[low] : min;
                low = mid + 1;
            }
            else{
                min = arr[mid] <= min ? arr[mid] : min;
                high = mid - 1;
            }
        }
        // now we have the min ele 
        // we only need to find out the position of that ele
        auto it = find(arr.begin(), arr.end(), min);
        int index = it - arr.begin();
        
        return index;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends