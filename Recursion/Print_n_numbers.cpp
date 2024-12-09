#include <bits/stdc++.h>
using namespace std;

void reverse(int n){
    if(n == 0){
        return;
    }

    // head recursion
    reverse(n - 1);
    cout << n << " ";
}

int main(){
    reverse(5);
    return 0;
}