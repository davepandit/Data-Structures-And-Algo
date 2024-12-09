#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int inversion_count(vector<int> &arr, int i, int count){
        int n = arr.size();
        int min = i;
        // base case 
        if(i == n - 1){
            return count;
        }
        // for one pass
        for(int j = i + 1; j < n; j++){
            if(arr[min] > arr[j]){
                count++;
            }
        }
        // recursion 
        return inversion_count(arr, i + 1, count);
}

int main(){
    vector<int> arr = {2, 3, 4, 5, 6};
    int ans = inversion_count(arr, 0, 0);
    cout << ans << endl;
    return 0;
}