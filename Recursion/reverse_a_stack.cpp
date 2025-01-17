#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int temp){
    // base condition 
    if(st.empty()){
        st.push(temp);
        return;
    }
    // hypothesis 
    int top_ele = st.top();
    st.pop();
    insert(st, temp);

    // induction 
    st.push(top_ele);
}

void reverse_stack(stack<int>& st){
    int s = st.size();
    // base condition 
    if(st.empty()){
        return;
    }
    // hypothesis
    int top_ele = st.top();
    st.pop();
    // call again
    reverse_stack(st);
    // induction 
    // this in itself will be a recursion 
    insert(st, top_ele);

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    // making a stack out of this
    stack<int> st;
    for(int i = 0; i < arr.size(); i++){
        st.push(arr[i]);
    }
    reverse_stack(st);

    // print the stack 
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}