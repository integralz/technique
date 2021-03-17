pair <ll, ll> ex_Euclidean(int a, int b)
{
    int s[2] = {1,0},t[2]={0,1},r[2] = {a,b},q,tmp;
    while(r[1])
    {
        q = r[0]/r[1];

    tmp = r[0]-r[1]*q;
    r[0] = r[1];
    r[1] = tmp;
    if(r[1]==0)
        break;

    tmp = s[0] - s[1]*q;
    s[0] = s[1];
    s[1] = tmp;

    tmp = t[0] - t[1]*q;
    t[0] = t[1];
    t[1] = tmp;
    }
    return {s[1],t[1]};
}
