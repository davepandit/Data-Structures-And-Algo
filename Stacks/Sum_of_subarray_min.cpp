#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

vector<int> min_subarray_sum(vector<int> arr){
    stack<int> st;
    vector<int> res;
    for(int i =  0; i < arr.size(); i++){
        // this loop is meant for selecting 1, 2, 3, 4 ele at once
        for(int j = i; j < arr.size(); j++){
            // this is to print the 1, 2, 3, ele at once
            for(int k = i; k <= j; k++){
                st.push(arr[k]);
            }
            // get the minimum from the stack
            int min = st.top();
            while(!st.empty()){
                st.pop();
                if(!st.empty() && st.top() < min){
                    min = st.top();
                }
            }
            // now we have the min
            // push the res
            res.push_back(min);
        }
    }

    return res;
}

int main(){
    vector<int> arr = {11,81,94,43,3};
    vector<int> ans_arr = min_subarray_sum(arr);

    int count = 0;
    for(int i = 0; i < ans_arr.size(); i++){
        count += ans_arr[i];
    }

    cout << "The sum of the min ele is: " << count << endl;
    return 0;

}