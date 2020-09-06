typedef long long ll;
ll mod = 1000000007;

ll solve(ll A, vector<ll>& count){
    if(A < 2) return 0ll;
    if(A < 3) return 1ll;
    if(A < count.size() && count[A] != -1ll) return count[A];
    ll ans = 0ll;
    for(ll i = 0ll; i < A; i+=2ll){
        ans = (ans + (max(1ll, solve(i, count)) * max(1ll,solve(A-i-2ll, count)))%mod)%mod;
    }
    return (int)(count[A] = (ans%mod));
}

int Solution::chordCnt(int A) {
    A = (2ll*A)%mod;
    vector<ll> count(A+1, -1ll);
    return (int)(solve((ll)A, count)%mod);
}