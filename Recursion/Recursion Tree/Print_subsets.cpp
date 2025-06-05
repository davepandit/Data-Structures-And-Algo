#include <bits/stdc++.h>
using namespace std;

void printSubsets(string ip, string op){
    if(ip.length() == 0){
        cout << op << endl;
        return;
    }

    // we need to make the input smaller 
    string op1 = op;
    string op2 = op + ip[0];

    // erase the first letter from the ip
    ip.erase(ip.begin() + 0);

    // now we can call for the left and the right parts 
    printSubsets(ip, op1);
    printSubsets(ip, op2);
}

int main(){
    string s = "ab";
    // initialise the op with some value 
    string op = "";
    printSubsets(s, op);
    return 0;
}