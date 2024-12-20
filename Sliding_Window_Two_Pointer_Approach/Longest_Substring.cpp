#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_longest_substring(string s){
    // find all the substring 
    // calculate the length 
    int max_len = 0;
    for(int i = 0; i < s.size(); i++){
        int len = 0;
        vector<int> hash_array(255, 0);
        for(int j = i; j < s.size(); j++){
            if(hash_array[s[j]] != 0){
                break;
            }
            hash_array[s[j]]++;
            len++;
            max_len = max(len, max_len);
        }
    }

    // here we will have the max length 
    return max_len;
}

int main(){
    string s = "pwwkew";
    int ans = find_longest_substring(s);
    cout << "The max length of the substring is: " << ans;
    return 0;
}