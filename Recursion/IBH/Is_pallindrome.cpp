class Solution {
  public:
    int solve(string s, string& sCopy){
        if(s.size() == 0){
            return true;
        }
        
        // take out the first ele 
        char ch = s[0];
        
        // make the input smaller 
        s.erase(s.begin());
        
        // call for the function again 
        bool res = solve(s, sCopy);

        // then compare
        if(ch != sCopy[0]) {
            return false;
        }

        sCopy.erase(sCopy.begin());

        return res;
    }
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // using the IBH method 
        string sCopy = s;
        
        
        return solve(s, sCopy);
        
    }
};