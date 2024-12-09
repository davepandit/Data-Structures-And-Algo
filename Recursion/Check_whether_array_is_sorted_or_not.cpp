#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>* arr, int s) {
    // Base case: If the size of the array is 0 or 1, it is considered sorted
    if (s == 0 || s == 1) {
        return true;
    }
    
    // If the current element is greater than the next one, the array is not sorted
    if ((*arr)[0] > (*arr)[1]) {
        return false;
    }
    
    // Make a subvector and check recursively for the rest of the array
    vector<int> subvector(arr->begin() + 1, arr->end());
    return isSorted(&subvector, s - 1);  // Ensure the result of recursion is returned
}

int main() {
    vector<int> arr = {12, 25, 89};
    bool ans = isSorted(&arr, arr.size());  // Pass the correct size of the vector

    if (ans) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not Sorted" << endl;
    }
    return 0;
}
