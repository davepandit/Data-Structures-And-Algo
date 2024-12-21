#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_arr(vector<int> arr, int goal){
    int l = 0, r = 0, sum = 0, count = 0;
    int n = arr.size();
    if(goal < 0){
        return 0;
    }
    while(l < n && r < n){
        sum = sum + arr[r];
        while(sum > goal){
            sum = sum - arr[l];
            l++;
        }
        count = count + (r - l + 1);
        r++;
    }
    return count;
    
}

int main(){
    vector<int> arr = {1,0,1,0,1};
    int goal = 2;
    int ans = find_arr(arr, goal) - find_arr(arr, goal - 1);
    cout << "The no of subarrays possible is: " << ans;
    return 0;
}