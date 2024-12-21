#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_nice_subarrays(vector<int> arr, int goal){
    int n = arr.size();
    int count = 0;
    // generate all the subarrays and cout the number of odd numbers 
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            int odd_count = 0;
            for(int k = i; k <= j; ++k){
                if(arr[k] % 2 != 0){
                    odd_count++;
                }
            }
            // now we have the number of the odd numbers ka count in a subarray 
            // we need to check whether that is equal to the goal 
            if(odd_count == goal){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> arr = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    int ans = find_nice_subarrays(arr, k);
    cout << "The no of nice subarrays is: " << ans;
    return 0;
}