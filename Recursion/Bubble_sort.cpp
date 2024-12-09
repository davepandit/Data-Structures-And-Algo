#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

void bubble_sort(vector<int> &arr, int n, int i){
        // base case
        if(i == n - 1){
            return;
        }
        // for one step
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                // swap
                swap(arr[j], arr[j + 1]);
            }
        }

        // recursion 
        bubble_sort(arr, n, i + 1);
}

int main(){
    vector<int> arr = {12, 24, 2, 1};
    bubble_sort(arr, arr.size(), 0);

    for(auto it:arr){
        cout<< it<< " ";
    }
    return 0;
}