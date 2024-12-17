#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

string remove_k_digits(string s, int k){
    stack<char> st;
    int i = 0;
    while(k > 0 && i < s.size()){
        // remove the smaller ones
        while(!st.empty() && st.top() > s[i] && k > 0){
            st.pop();
            // reduce the value of k 
            k = k - 1;
        }
        // push the smaller ones into the stack
        st.push(s[i]);

        // increase the value of i
        i = i + 1;

    }
    // push the remaining ones to the stack 
    while(i < s.size()){
        st.push(s[i]);
        i++;
    }
    // check for k 
    while(k > 0 && !st.empty()){
        st.pop();
        k = k - 1;
    }

    // reverse the stack ele 
    vector<char> ans_arr;
    while(!st.empty()){
        // push the ele into the array
        ans_arr.push_back(st.top());
        st.pop();
    }

    reverse(ans_arr.begin(), ans_arr.end());
    string ans_str;
    for(int i = 0; i < ans_arr.size(); i++){
        ans_str.push_back(ans_arr[i]);
    }

    // remove the leading zeroes
    while (!ans_str.empty() && ans_str[0] == '0'){
        ans_str.erase(ans_str.begin());
    }
    return ans_str.empty() ? "0" : ans_str;
}

int main(){
    string s = "1432219";
    int k = 3;
    // k means the number of digits that we can remove 
    string ans = remove_k_digits(s, k);
    cout << "Result is: " << ans <<endl;
    return 0;
}