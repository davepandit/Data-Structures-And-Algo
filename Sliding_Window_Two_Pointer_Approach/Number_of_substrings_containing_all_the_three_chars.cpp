#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_number_of_subarrays(vector<int> arr){
    int n = arr.size();
    int count = 0;
    // generate all the subarrays and keep a hash map that can track whether all the ele
    // are there in that or not
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            vector<int> hash(3, 0);
            for(int k = i; k <= j; ++k){
                hash[arr[k] - 'a']++;
            }
            // we have the hash ready now 
            // check whether any of the ele in the hash arrat is 0 or not
            int flag = 0;
            for(int index = 0; index < hash.size(); ++index){
                if(hash[index] == 0){
                    flag++;
                }
            }
            // if flag == 0 then all the chars are present and we can increase the count
            if(flag == 0){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<int> arr = {};
    int ans = find_number_of_subarrays(arr);
    cout << "The no of nice subarrays is: " << ans;
    return 0;
}