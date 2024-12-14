#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

vector<int> second_greater_ele(vector<int> arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans_arr(n, -1);
    // travserse the array from the right end
    for(int i = n - 1; i >= 0; --i){
        if(st.empty()){
            ans_arr[i] = -1;
            st.push(arr[i]);
        }else{
            if(st.top() > arr[i]){
                ans_arr[i] = st.top();
                st.push(arr[i]);
            }else{
                while(!st.empty() && st.top() <= arr[i]){
                    st.pop();
                }
                ans_arr[i] = st.empty() ? -1 : st.top() ;
                st.push(arr[i]);
            }
        }
    }

    return ans_arr;
}

int main(){
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> ans_arr = second_greater_ele(arr);
    for(int i = 0; i < ans_arr.size(); i++){
        cout << ans_arr[i] << " ";
    }
    return 0;
}