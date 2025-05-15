// this is pretty similar to the lower_bound with some little tweaks 

// c++ specific
// int index = lower_bound(arr.begin(), arr.end(), n) - arr.begin();

#include <bits/stdc++.h>
using namespace std;
// nums[index] >= n, where index is the smallest one 
int lower_bound(vector<int>& nums, int n){
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] <= n){
            ans = nums[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    return 0;
}