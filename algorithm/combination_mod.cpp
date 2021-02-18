c[0] = 1;
inv[0] = 1;
 
int cal(int a, int b){
    if(a < b) return 0;
    else{
        return c[a] * inv[b] % mod * inv[a - b] % mod;
    }
}
 
long long make_inv(long long a, int b){
    long long ans = 1;
    while(b){
        if(b % 2 ==0){
            a = a*a % mod;
            b /= 2;
        }
        else{
            ans = ans * a % mod;
            --b;
        }
    }
    return ans;
}

