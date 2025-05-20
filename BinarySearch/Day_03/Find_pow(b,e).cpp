// this calculates the pow(b,e) in logarithmic time 
// time complexity -> log2 n

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