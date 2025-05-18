class Solution {
public:
    bool check(vector<int>& arr) {
        // consider the example -> [3,4,5,1,2]
        int pos = -1;
        // this is also using the linear search 
        for(int i = 0; i < arr.size() - 1; ++i){
            if(arr[i] > arr[i + 1]){
                pos = i;
                break;
                // [3,4,5,1,2] found the index of 5 in the array and then we need to check for the part after 5 whether it is sorted or not
            }
        }
        if(pos == -1){
            return true;
        }
        // we need to keep a check 
        // checking for the part after 5 whether it is sorted or not 
        else if(pos != -1){
            // check for the rest of the part of the array 
            for(int i = pos + 1; i < arr.size() - 1; ++i){
                if(arr[i] > arr[i + 1]){
                    return false;
                }
            }
        }

        // also another check that either saach me the array is rotated or not or like🧊
        if(arr[0] < arr[arr.size() - 1]){
            return false;
        } 
        // if we reach here then we can return true
        return true;
    }
};