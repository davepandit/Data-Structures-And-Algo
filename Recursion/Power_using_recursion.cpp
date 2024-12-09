#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int power(int base, int exp){
    // base case
    if(exp == 0){
        return 1;
    }
    // recursive function 
    return base * power(base, exp - 1);
}

int main(){
    int base = 3;
    int exp = 11;
    int ans = power(base, exp);
    cout << base << " raise to the power " << exp << " is: " << ans;
    return 0;
}