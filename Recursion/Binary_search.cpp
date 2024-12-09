#include<bits/stdc++.h>
using namespace std;

bool binary_search(int arr[], int low, int high, int k){
    if(low > high){
        return false;
    }
    int mid = (low + high)/2;
    if(k > arr[mid]){
        low = mid + 1;
        binary_search(arr, low, high, k);
    }else if(k < arr[mid]){
        high = mid - 1;
        binary_search(arr, low, high, k);
    }else{
        return true;
    }
}

int main(){
    int arr[3] = {1, 2, 4};
    bool ans = binary_search(arr, 0, 3, 90);
    if(ans){
        cout<< "True"<< endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}