#include <bits/stdc++.h>
using namespace std;

class Demo{
    
};

int sum(vector<int>* arr, int s, int ans){
    if(s == 1){
        return ans;
    }
    ans = (*arr)[0] + (*arr)[1];
    vector<int> subvector(arr->begin() + 1, arr->end());
    subvector[0] = ans;
    return sum(&subvector, s - 1, ans);
}

int main(){
    vector<int> arr = {1, 2, 3};
    int ans = 0;
    int new_ans = sum(&arr, arr.size(), ans);
    cout<< new_ans << endl;
    return 0;
}





// <--------- OR CODE --------->
#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate sum
int sum(vector<int>& arr, int s) {
    // Base case: If the array is empty, return 0
    if (s == 0) {
        return 0;
    }
    
    // Add the first element and recursively calculate the sum for the rest
    return arr[0] + sum(arr, s - 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int total_sum = sum(arr, arr.size());
    cout << "Sum of elements: " << total_sum << endl;
    return 0;
}
