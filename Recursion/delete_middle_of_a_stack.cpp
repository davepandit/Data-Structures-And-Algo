#include <bits/stdc++.h>
using namespace std;

void delete_middle_ele(stack<int>& st){
    static int s = st.size(), count = 0;
    static int mid = (s / 2) + 1;
    // base condition 
    if(count == mid){
        return;
    }
    // hypothesis
    // take the last ele out and then again call the function 
    int top_ele = st.top();
    // pop the ele
    st.pop();
    count++;
    delete_middle_ele(st);
    // induction  
    if (count == mid) {
        count--;
    } else {
        st.push(top_ele);
    }}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    // make a stack out of this 
    stack<int> st;
    for(int i = 0; i < arr.size(); i++){
        st.push(arr[i]);
    }
    delete_middle_ele(st);
    // printing the ele of the stack 
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}