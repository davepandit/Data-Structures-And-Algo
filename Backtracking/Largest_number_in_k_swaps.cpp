// this is an incorrect solution 
// this approach uses greedy which could have been used when there were no duplicates in the 
// string 
// since this string contains duplicate this approach fails.

class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        int index = 0;
        while(k != 0 && index < s.size()){
            int max = index;
            for(int i = index + 1; i < s.size(); i++){
                max = s[i] >= s[max] ? i : max;
            }
            
            if(s[max] != s[index]){
                // swap
                swap(s[index], s[max]);
                k = k - 1;
            }
            // move the index 
            index = index + 1;
        }
        
        return s;
    }
};