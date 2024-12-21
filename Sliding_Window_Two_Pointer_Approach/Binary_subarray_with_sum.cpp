#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_arr(vector<int> arr, int g){
    int n = arr.size();
    // generate all the subarrays and find the sum 
    // if the sum is equal to the goal then increase the count 
    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            int sum = 0;
            for(int k = i; k <= j; ++k){
                sum = sum + arr[k];
            }
            // here we have computed the result of the subarray 
            if(sum == g){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<int> arr = {0,0,0,0,0};
    int ans = find_arr(arr, 0);
    cout << "The no of subarrays possible is: " << ans;
    return 0;
}