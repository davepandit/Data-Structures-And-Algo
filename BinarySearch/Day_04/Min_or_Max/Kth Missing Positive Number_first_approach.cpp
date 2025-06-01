class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int ans = -1;
        while(k > 0){
            if(find(arr.begin(), arr.end(), num) == arr.end()){
                k = k - 1;
                ans = num;
            }
            num = num + 1;
        }

        return ans;
    }
};