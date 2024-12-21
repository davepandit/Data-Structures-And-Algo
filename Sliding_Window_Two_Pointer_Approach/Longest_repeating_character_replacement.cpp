#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};


int longest_substring(string s, int k){
    int n = s.size();

    int l = 0, r = 0, len = 0, max_len = 0, max_freq = 0;
    map<char, int> mpp;

    while(l < n && r < n){
        len = r - l + 1;
        mpp[s[r]]++;
        max_freq = max(max_freq, mpp[s[r]]);
        while(len - max_freq > k){
            mpp[s[l]]--;
            l++;
            len = r - l + 1;
        }

        max_len = max(max_len, len);
        r++;

    }
    return max_len;
}

int main(){
    string s = "AABABBA";
    int ans = longest_substring(s, 1);
    cout << "Ans is: " << ans;
    return 0;
}