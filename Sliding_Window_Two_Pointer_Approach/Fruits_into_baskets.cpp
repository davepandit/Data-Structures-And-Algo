#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int put_fruits_into_baskets(vector<int> arr){
    int n = arr.size();
    int l = 0, r = 0, len = 0, max_len = 0;
    map<int, int> mpp;
    // insert every ele into the map
    // ask the map how many unique ele are there in the map
    // if the map replies with more than 2 then keep on removing the ele from the beginning
    // and move the l pointer until the map says there are 2 ele
    while(l < n && r < n){
        mpp[arr[r]]++;
        while(mpp.size() > 2){
            // remove the ele from the mpp
            mpp[arr[l]]--;
            // before moving the l pointer just check whether the count for that ele is zero or not 
            // if yes then remove that ele from the mpp
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            // keep on moving the left pointer to the right 
            l++;            
        }

        // calculate the len 
        len = r - l + 1;
        max_len = max(max_len, len);
        r++;
    }

    // here we have the max len 
    return max_len;
    
}

int main(){
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    int ans = put_fruits_into_baskets(arr);
    cout << "Ans is : " << ans;
    return 0;
}