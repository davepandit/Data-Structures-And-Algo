#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

void sayDigits(int n){
    if(n == 0){
        return;
    }
    // head recursion
    sayDigits(n / 10);
    // processing
    int digit = n % 10;
    cout << digit << " ";
}

int main(){
    int n = 412;
    sayDigits(n);
    return 0;
}