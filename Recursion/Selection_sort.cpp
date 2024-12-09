#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

void selection_sort(vector<int> &arr, int n, int i){
        int min = i;
        // base case
        if(i == n - 1){
            return;
        }
        // for one pass
        for(int j = i + 1; j <= n - 1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);

        // recursion 
        selection_sort(arr, n, i + 1);
}

int main(){
    vector<int> arr = {12, 2, 45, 23, 1};
    selection_sort(arr, arr.size(), 0);

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}