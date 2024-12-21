#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int max_score(vector<int> arr, int k){
    int n = arr.size();
    int l_sum = 0, r_sum = 0, sum = 0;
    // calculate the sum of the first k ele from the front
    // and then keep on removing one ele from the front
    // and keep on adding one ele from the back
    for(int i = 0; i < k; ++i){
        l_sum = l_sum + arr[i];
    }
    // now we have the sum of the first k ele and now keep on removing one ele from the front 
    sum = l_sum;
    int r_index = n - 1;
    for(int i = k - 1; i >= 0; --i){
        l_sum = l_sum - arr[i];
        r_sum = r_sum + arr[r_index];
        r_index--;
        sum = max(sum, l_sum + r_sum);
    }

    return sum;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    int ans = max_score(arr, k);
    cout << "The no of substrings is: " << ans;
    return 0;
}