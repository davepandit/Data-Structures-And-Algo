// return all the substrings of a string that are pallindrome 


#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string& s){
    string sCopy = s;
    reverse(sCopy.begin(), sCopy.end());

    for(int i = 0; i < s.size(); ++i){
        if(s[i] != sCopy[i]){
            return false;
        }
    }

    return true;
}

set<string> generateSubstring(string& s){
    set<string> st;
    for(int i = 0; i < s.size(); ++i){
        string subStr = "";
        for(int j = i; j < s.size(); ++j){
            subStr.push_back(s[j]);
            st.insert(subStr);
        }
    }

    return st;
}

int main(){
    string s = "aab";
    set<string> st = generateSubstring(s);

    vector<string> ans;
    for(auto it : st){
        if(isPallindrome(it)){
            ans.push_back(it);
        }
    }

    for(auto it : ans){
        cout << it << endl;
    }
    return 0;
}