#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

vector<int> second_greater_ele(vector<int> arr){
    stack<int> st;
    int max_ele = arr[0];
    // travserse the whole arr and store the max ele in the stack
    // then do the normal stuff like in the first part 
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > max_ele){
            max_ele = arr[i];
        }
    }
    // now we have the max ele, push it to the stack 
    st.push(max_ele);

    int n = arr.size();
    vector<int> ans_arr(n, -1);
    for(int i = n - 1; i >= 0; --i){
        if(st.empty()){
            ans_arr[i] = -1;
            st.push(arr[i]);
        }else{
            if(!st.empty() && st.top() > arr[i]){
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
    vector<int> arr = {1, 2, 1};
    vector<int> ans_arr = second_greater_ele(arr);
    for(int i = 0; i < ans_arr.size(); i++){
        cout << ans_arr[i] << " ";
    }
    return 0;
}