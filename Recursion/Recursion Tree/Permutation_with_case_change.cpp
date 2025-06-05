#include <bits/stdc++.h>
using namespace std;

void permutationWithCase(string ip, string op){
    if(ip.length() == 0){
        cout << op << endl;
        return;
    }

    // we need to choose whether to change the case or not 
    string op1 = op; // here we will not change the case
    op1.push_back(ip[0]);
    string op2 = op; // here we will change the case 
    op2.push_back(ip[0] - 32);

    // make the input smaller 
    ip.erase(ip.begin() + 0);
    // call for the smaller halves 
    permutationWithCase(ip, op1);
    permutationWithCase(ip, op2);
}

int main(){
    string ip = "abc";
    // initialise the op with something 
    string op = "";
    permutationWithCase(ip, op);
    return 0;
}