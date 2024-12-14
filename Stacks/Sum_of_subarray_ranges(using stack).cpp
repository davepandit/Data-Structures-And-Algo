#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

vector<int> find_nse(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n, n); // Initialize with n (default value for no smaller element)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
}
vector<int> find_psee(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> psee(n, -1); // Initialize with -1 (default value for no smaller element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
}

vector<int> find_nge(vector<int> arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n, n);
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
}
vector<int> find_pgee(vector<int> arr){
    stack<int> st;
    int n = arr.size();
    vector<int> pgee(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
}

long long sum_of_subarray_ranges(vector<int> arr){
    int n = arr.size();
    vector<int> nse = find_nse(arr);
    vector<int> psee = find_psee(arr);
    vector<int> nge = find_nge(arr);
    vector<int> pgee = find_pgee(arr);

    long long min_total = 0;
    long long max_total = 0;

    const long long mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        long long min_right = nse[i] - i;
        long long min_left = i - psee[i];
        long long max_right = nge[i] - i;
        long long max_left = i - pgee[i];
        
        min_total = (min_total + (min_left * min_right % mod) * arr[i] % mod) % mod;
        max_total = (max_total + (max_left * max_right % mod) * arr[i] % mod) % mod;
    }

    long long ans = max_total - min_total;
    return ans;
}


int main(){
    vector<int> arr = {4,-2,-3,4,1};
    
    long long ans = sum_of_subarray_ranges(arr);
    cout << "The sum is: " << ans;
    return 0;

}