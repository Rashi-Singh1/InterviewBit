//O(N) time and O(N^2) space solution
//gives MLE
typedef long long ll;
ll mod = 1000000007;
ll solve(string A, ll start, ll end, vector<vector<ll> >& count){
    if(start > end) return 1ll;
    if(start == end) return (A[start] == '0' ? 0ll : (count[start][end] = 1ll));
    if(count[start][end] != -1) return count[start][end]%mod;
    ll mid = (start + end)/2;
    ll temp = 1;    
    if(end > start) temp = solve(A, start, mid, count);
    ll temp2 = solve(A, mid+1, end, count);
    temp = (temp * temp2)%mod;
    if(A[mid] == '1' || (A[mid] == '2' && A[mid+1] < '7')) temp = (temp + (solve(A, start, mid-1, count)*solve(A, mid+2, end, count))%mod)%mod; 
    return (count[start][end] = temp)%mod;
}

int Solution::numDecodings(string A) {
    if(A.size() == 0) return 0;
    vector<ll> temp(A.size(), -1);
    vector<vector<ll> > count(A.size(), temp);
    return (int)(solve(A, 0ll, (ll)A.size()-1, count)%mod);
}

//O(N) time and space solution
//same idea as above, just fixing the start (i.e. now working on prefix)
typedef long long ll;
ll mod = 1000000007;
int Solution::numDecodings(string A) {
    if(A.size() == 0 || A[0] == '0') return 0;
    vector<ll> count(A.size()+1, 1ll);
    for(int i = 2 ; i <= A.size(); i++){
        if(count[i] == count[i-1] && count[i] == 0) return 0;
        if(A[i-1] == '0') count[i] = 0ll;
        count[i] = (count[i]*count[i-1])%mod;
        if(A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7')) count[i] = (count[i] + count[i-2])%mod;
    }
    return (int)count[A.size()]%mod;
}