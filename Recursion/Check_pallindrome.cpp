#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

bool checkPallindrome(string &s, int i, int j){
    // base case 
    if(i > j){
        return true;
    }
    if(s[i] == s[j]){
        checkPallindrome(s, i + 1, j - 1);
    }else{
        return false;
    }
}

int main(){
    string s = "madam";
    bool ans = checkPallindrome(s, 0, s.size() - 1);
    if(ans){
        cout<< "Pallindrome"<< endl;
    }else{
        cout<< "Not a pallindrome";
    }
    return 0;
}