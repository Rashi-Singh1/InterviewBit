long long int mo;
bool solve(long long int mid, vector<int> &C, int painters)
{
    mo = 10000003;
    long long int tim = 0;
    long long int count = 0;
    long long int trash = tim;
    for(int i = 0;i<C.size();i++)
    {
        tim+=(long long int)((long long int)C[i]%mo);
        trash = tim;
        if(tim>=mid)
        {
            if(tim != mid) i--;
            count+=1%mo;
            tim = 0;
        }
        if(count > painters) return false;
    }
    if(trash < mid) count+=1%mo;
    if(count > painters) return false;
    return true;
}

int Solution::paint(int painters, int speed, vector<int> &C) {
    if(C.size() == 0 || speed == 0) return 0;
    mo = 10000003;
    long long int sum = (1ll*C[0])%mo;
    for(int i = 1;i<C.size();i++)
    {
        sum+=(long long int)C[i]%mo;
    }
    long long int start = 0;
    long long int end = sum%mo;
    long long int ans = end;
    while(start <= end)
    {
        long long int mid = (start + end)/2;
        if(solve(mid,C,painters))
        {
            ans = min(ans,mid);
            end = mid - 1;
        }else start = mid+1;
    }
    return (int)(((ans%mo)*speed)%mo);
}
