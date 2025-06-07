class Solution {
public:
    void solve(vector<int> ip, vector<int> op, long long& count, int target){
        if(ip.size() == 0 && op.size() != 0){
            // then we can perform some operation on the count 
            int min = op[0];
            int max = op[op.size() - 1];

            if(min + max <= (long long)target){
                count++;
            }

            return;
        }
        else if(ip.size() == 0 && op.size() == 0){
            return;
        }


        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);

        // make the ip smaller 
        ip.erase(ip.begin());

        // call the function again 
        solve(ip, op1, count, target);
        solve(ip, op2, count, target);
    }
    int numSubseq(vector<int>& nums, int target) {
        // here we have some choices ans based on those choices 
        // we can take some decisions 
        // so we can use recursion 

        vector<int> op;
        long long count = 0;

        // sort the array before passing because 
        // then we need not traverse the array later to find the min and the max ele 
        sort(nums.begin(), nums.end());

        solve(nums, op, count, target);

        long long MOD = 1e9 + 7;
        count = count % MOD;

        return (int)count;
    }
};