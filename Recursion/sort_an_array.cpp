#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& arr, int temp){
    // base condition 
    if(arr.size() == 0 || arr[arr.size() - 1] <= temp){
        // then we can insert and can return
        arr.push_back(temp);
        return;
    }
    // hypothesis
    // remove the last ele and then again call the insert function 
    int last_ele = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, last_ele); 

    // induction 
    // simply dal do the ele which we have removed while making the input shorter 
    arr.push_back(last_ele);
}

void sort_array(vector<int>& arr){
    int n = arr.size();
    // this is to be done using recursion 
    // base condition 
    if(n == 1){
        // there is only one ele and the array is sorted 
        return ;
    }
    // hypothesis
    // take out the last ele and then call the sort function 
    int last_ele = arr[n - 1];
    // pop out the last ele
    arr.pop_back();

    sort_array(arr);

    // induction 
    insert(arr, last_ele);
}

int main(){
    vector<int> arr = {1, 4, 3, 2, 5};
    sort_array(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}