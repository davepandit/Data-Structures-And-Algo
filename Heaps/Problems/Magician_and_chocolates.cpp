int Solution::nchoc(int A, vector<int> &B) {
    // ek bag ke aandar jitna bhi chocolates hai the kid can eat that in a unit time
    // after one unit time the magician fills the bag with Bi / 2 chocolates
    
    // we need to return the max chocolates that can be eaten
    // we will be using a max heap
    priority_queue<int> pq;
    int n = B.size();
    const int MOD = 1e9 + 7;
    
    // push all the ele into the pq
    for(int i = 0;i < n; ++i){
        pq.push(B[i]);
    }
    
    long long chocolatesEaten = 0;
    while(A > 0){
        // take out the top ele 
        int noOfChocolates = pq.top();
        pq.pop();
        
        chocolatesEaten += noOfChocolates;
        
        // the magician enters noOfChocolates / 2 into the respective bag
        pq.push(noOfChocolates / 2);
        A = A - 1;
    }
    
    return chocolatesEaten % MOD;
}
