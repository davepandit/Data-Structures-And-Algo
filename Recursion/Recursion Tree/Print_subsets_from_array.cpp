#include <bits/stdc++.h>
using namespace std;

void printSubsets(vector<int> ip, vector<int> op) {
    if(ip.size() == 0){
        // print the output subsequence
        for(int val : op){
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // make output: one excluding, one including ip[0]
    vector<int> op1 = op;
    vector<int> op2 = op;
    op2.push_back(ip[0]);

    // make the input smaller
    ip.erase(ip.begin());

    // recursive calls
    printSubsets(ip, op1);
    printSubsets(ip, op2);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> op;
    printSubsets(arr, op);
    return 0;
}
