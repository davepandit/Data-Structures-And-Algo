#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

vector<int> second_greater_ele(vector<int> arr){
    // two pointer approach 
    // on the same lines as that of the selection sort 
    vector<int> ans_arr;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int sec_max = i;
        int flag = 0;
        for(int j = i; j < n; j++){
            if(arr[j] > arr[sec_max]){
                sec_max = j;
                flag = 1;
                break;
            }
        }
        // we have the sec max
        // push into the ans array
        if(flag != 0){
            ans_arr.push_back(arr[sec_max]);
        }else{
            ans_arr.push_back(-1);   
        }
    }
    return ans_arr;
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    vector<int> ans_arr = second_greater_ele(arr);
    for(int i = 0; i < ans_arr.size(); i++){
        cout << ans_arr[i] << " ";
    }
    return 0;
}