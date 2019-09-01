
bool solve(long long int mid, vector<int> &C, int painters)
{
    long long int tim = 0;
    long long int count = 0;
    long long int trash = tim;
    for(int i = 0;i<C.size();i++)
    {
        tim+=(long long int)C[i];
        trash = tim;
        if(tim>=mid)
        {
            if(tim != mid) i--;
            count++;
            tim = 0;
        }
        if(count > painters) return false;
    }
    if(trash < mid) count++;
    if(count > painters) return false;
    return true;
}

int Solution::books(vector<int> &C,int painters) {
    if(C.size() < painters) return -1;
    long long int sum = (1ll*C[0]);
    for(int i = 1;i<C.size();i++)
    {
        sum+=(long long int)C[i];
    }
    long long int start = 0;
    long long int end = sum;
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
    return (int)ans;
}
