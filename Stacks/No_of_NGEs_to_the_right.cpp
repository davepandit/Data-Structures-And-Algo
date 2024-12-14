#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

vector<int> second_greater_ele(vector<int> arr, vector<int> indices, int queries){
        // stack should contain the number of ele that are greater
        // than the ele ka index provided in the indices array
        // ouput array ka first index will be the size of the array and so on
        int n = arr.size();
        stack<int> st;
        vector<int> res;
        
        for(int i = 0; i < queries; i++){
            static int j = 0;
            int ele_ka_index = indices[j];
            // remember to increase this j;
            for(int k = n - 1; k > ele_ka_index; --k){
                if(arr[k] > arr[ele_ka_index]){
                    st.push(arr[k]);
                }
            }
            res.push_back(st.size());
            
            // clear the stack 
            while(!st.empty()){
                st.pop();
            }
            j = j + 1;
        }
        
        return res;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 1};
    vector<int> indices = {0, 3};
    vector<int> ans_arr = second_greater_ele(arr, indices, 2);
    for(int i = 0; i < ans_arr.size(); i++){
        cout << ans_arr[i] << " ";
    }
    return 0;
}