#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int target){
    int n = arr.size();

    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(arr[mid] == target){
            return mid;
        }
        else if(target > arr[mid]){
            // move the low pointer 
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    // we will reach here agar hume ele mile hi na 
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;
    int index = binary_search(arr, target);
    cout << index;
    return 0;
}