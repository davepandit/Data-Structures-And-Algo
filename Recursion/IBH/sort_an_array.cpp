class Solution {
  public:
    void insertIntoCorrectPos(vector<int>& arr, int n, int ele){
        if(n == 0 || arr[n - 1] <= ele){
            // then we can directly insert the ele 
            arr.push_back(ele);
            return;
        }
        
        // take out the bigger ele 
        int bigEle = arr[n - 1];
        // pop the ele 
        arr.pop_back(); 
        // call for the function again
        insertIntoCorrectPos(arr, n - 1, ele);
        // insert the bigger ele 
        arr.push_back(bigEle);
    }
    void solve(vector<int>& arr, int n){
        if(n == 1){
            // then to soerted hi hai 
            return;
        }
        
        // take out the last ele 
        int ele = arr[n - 1];
        // pop the last ele 
        arr.pop_back();
        
        // solve for smaller input jisme last ele nahi hai 
        solve(arr, n - 1);
        
        // now we need to insert ele in its correct position 
        insertIntoCorrectPos(arr, n - 1, ele);
    }
    void sortArr(vector<int> &arr) {
        // using the IBH method 
        
        int n = arr.size();
        solve(arr, n);
        
    }
};