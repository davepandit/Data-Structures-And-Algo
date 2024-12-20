#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int max_ones(vector<int> arr, int m){
    int n =  arr.size();
    int max_len = 0;
    // generate the subarrays and find the one with the max number of zeroes where the max should 
    // be equal to k 
    // for the starting address 
    for(int i = 0; i < n; i ++){
        // for the ending index
        for(int j = i; j < n; j++){
            int z_len = 0;
            int len = 0;
            for(int k = i; k <= j; k++){
                if(z_len == m){
                    if(arr[k] == 0){
                        break;
                    }
                }
                if(arr[k] == 0 && z_len < m){
                    z_len++; 
                }
                
                if(arr[k] == 1){
                    len++;
                }
            }
            max_len = max(max_len, len + z_len);
            
        }
        
    }
    // here we have the max len 
    return max_len;
}


int main(){
    vector<int> arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    int ans = max_ones(arr, k);
    cout << "Ans is: " << ans;
    return 0;
}