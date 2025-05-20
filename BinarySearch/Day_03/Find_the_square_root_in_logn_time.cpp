#include <bits/stdc++.h>
using namespace std;

int square_root(int num){
    int low = 1, high = num, ans = 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid * mid == num){
            return mid;
        }
        else if(mid * mid < num){
            ans = mid;
            // eliminate the left search space
            low = mid + 1;
        }
        else{
            // eliminate the right search space
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    int num = 38;
    int ans = square_root(num);
    cout << ans;
    return 0;
}