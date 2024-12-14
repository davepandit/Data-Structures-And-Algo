#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

void print_subarrays(vector<int> arr){
    for(int i =  0; i < arr.size(); i++){
        // this loop is meant for selecting 1, 2, 3, 4 ele at once
        cout << "The subarray starting with " << arr[i] << ": " << endl;
        for(int j = i; j < arr.size(); j++){
            // this is to print the 1, 2, 3, ele at once
            for(int k = i; k <= j; k++){
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    vector<int> arr = {3, 1, 2, 4};
    print_subarrays(arr);
    
    return 0;
}