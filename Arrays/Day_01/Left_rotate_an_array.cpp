#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int>& nums, int k){
    // algo 
    // reverse the array 
    // reverse the n -  k ele first
    // reverse the next k ele 
    int n = nums.size();
    k = k % n;
    // reverse the array 
    reverse(nums.begin(), nums.end());

    // reverse the first n - k ele
    reverse(nums.begin() , nums.begin() + n - k);

    // reverse the next k ele 
    reverse(nums.begin() + n - k, nums.end());
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    left_rotate(nums, k);
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    return 0;
}