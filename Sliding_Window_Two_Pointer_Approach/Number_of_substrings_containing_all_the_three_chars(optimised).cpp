#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int find_number_of_substrings(string s){
    // make one hash array 
    // that contains the last seen index of every char 
    // stand at one char and look for the smallest possible substring that has all the 3 chars 
    // if found then take that char ka index which has the least value because that is seen at the very first 
    // and then add one to that 
    // least index in the hash array + 1
    int n = s.size();
    int count = 0;
    int l = 0, r = 0;
    vector<int> hash(3, -1);
    while(l < n && r < n){
        hash[s[r] - 'a'] = r;
        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
            int least = hash[0];
            for(int i = 0; i < hash.size(); ++i){
                if(hash[i] < least){
                    least = hash[i];
                }
            }
            // now we have the leat value wala thing 
            count = count + (least + 1);
        }
        r++;
    }

    return count;
}

int main(){
    string s = "aaacb";
    int ans = find_number_of_substrings(s);
    cout << "The no of substrings is: " << ans;
    return 0;
}