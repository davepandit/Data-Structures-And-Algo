#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int target, int low, int high){
    if(low > high){
        return -1;
    }

    int mid = ( low + high ) / 2;
    if(target == arr[mid]){
        // then return 
        return mid;
    }
    else if(target > arr[mid]){
        // move to the right
        return binary_search(arr, target, mid + 1, high);
    }
    // else search in the left 
    return binary_search(arr, target, low, mid - 1);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;
    int low = 0, high = arr.size() - 1;
    int index = binary_search(arr, target, low, high);
    return 0;
}