ll CRT(ll n1, ll k1,ll n2, ll k2) // n = mod, k = remainder // X = retrunValue mod lcm(n1,n2)
{
    ll gc = gcd(n1,n2);
    ll lc = (n1*n2/gc);
    if((k2-k1)%gc)
        return -1;
    pair <ll, ll> x = ex_Euclidean(n1/gc,n2/gc);
    ll result = ((x.first*(k2-k1)/gc)*n1+k1)%lc;
    if(result<0)
        result += lc;
    return result;
}

