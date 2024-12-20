#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_max_ones(vector<int> arr, int k){
    int n = arr.size();
    int l = 0, r = 0;
    int max_len = 0;
    int z_count = 0;
    int len = 0;

    while(l < n && r < n){
        if(arr[r] == 0 && z_count < k){
            z_count++;
        }
        else if(arr[r] == 0 && z_count == k){
            z_count++;
            while(arr[l] != 0){
                l++;
            }
            // now we are at the first zero 
            // keep on increasing the l untill z_count is restored
            while(z_count > k){
                l++;
                z_count--;
            }
        }

        len = r - l + 1;
        max_len = max(max_len, len);
        r++;
    }


    return max_len;
}

int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int ans = find_max_ones(arr, 2);
    cout << "Ans is: " << ans;
    return 0;
}