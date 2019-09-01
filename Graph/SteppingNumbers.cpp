vector<int> ans;
void solve(long long int num, long long int a, long long int b)
{
    if(num >= a && num <= b)
    {
        ans.push_back(num);
    }
    else if(num > b) return;
    if(num%10 != 0) solve(num*10 + num%10 - 1,a,b);
    if(num%10 != 9) solve(num*10 + num%10 + 1,a,b);
}

vector<int> Solution::stepnum(int A, int B) {
    ans.clear();
    for(int i = 1;i<=9;i++) solve(1ll*i,1ll*A,1ll*B);
    if(A == 0) ans.push_back(0);
    sort(ans.begin(),ans.end());
    return ans;
}
