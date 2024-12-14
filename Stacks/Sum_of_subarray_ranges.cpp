#include <bits/stdc++.h>
using namespace std;

int min_sum(vector<int> arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        // This loop is meant for selecting 1, 2, 3, 4 elements at once
        for (int j = i; j < arr.size(); j++) {
            // Construct the subarray from `i` to `j`
            vector<int> ans_arr;  // Initialize an empty vector
            for (int k = i; k <= j; k++) {
                ans_arr.push_back(arr[k]);
            }
            
            // We have the subarray; compute the difference between max and min
            int min = ans_arr[0];
            int max = ans_arr[0];
            for (int l = 0; l < ans_arr.size(); l++) {
                if (ans_arr[l] < min) {
                    min = ans_arr[l];
                }
                if (ans_arr[l] > max) {
                    max = ans_arr[l];
                }
            }
            
            
            // Add the difference to the answer
            ans += max - min;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int ans = min_sum(arr);
    cout << "The min sum is: " << ans << endl;

    return 0;
}
