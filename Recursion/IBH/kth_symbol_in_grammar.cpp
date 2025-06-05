class Solution {
public:
    // logic to generate the kth symbol in the nth row 
    // i have attached one logic that i have thought off while solving the problem 
    // in the github repo 

    int solve(int n, int k){
        if(n == 1 && k == 1){
            return 0;
        }

        // in order to find the answer to the given n and k value we need to find the previous value
        return k % 2 == 0 ? !solve(n - 1, ceil(double(k) / 2)) : solve(n - 1, ceil(double(k) / 2)); 
    }

    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};