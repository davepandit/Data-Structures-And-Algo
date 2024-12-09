#include <iostream>
#include <string>
using namespace std;

// Recursive function to reverse a string
string reverseString(string str) {
    // Base case: If the string is empty or has one character, return it
    if (str.empty() || str.size() == 1) {
        return str;
    }
    
    // Recursive case: Reverse the rest of the string, then add the first character at the end
    return reverseString(str.substr(1)) + str[0];
}

int main() {
    string str = "hello";
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}
