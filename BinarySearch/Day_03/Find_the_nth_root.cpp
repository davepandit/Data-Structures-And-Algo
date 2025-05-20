int power(int b, int e){
    // b raise to the power n 
    long long ans = 1;
    while(e > 0){
        if(e % 2 == 1){
            ans = b * ans;
        }
        else{
            b = b * b;
            e = e / 2;
        }
    }

    return ans;
}

int nth_root(int n, int m){
    // we need to find m raise to the power 1/n
    int low = 1, high = m;
    while(low <= high){
        int mid = (low + high) / 2;
        if(power(mid, n) == m){
            return mid;
        }
        else if(power(mid, n) < m){
            // eliminate the left search space 
            low = mid + 1;
        }
        else {
            // eliminate the right search space 
            high = mid - 1;
        }
    }

    // yahan tak pahuch gaye then the nth root doesnot exist 
    return -1;
}