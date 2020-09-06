//did not work for test case 20
typedef long long ll;
ll mod = 1000000007;
ll comb[105][105];

ll find(ll A, vector<ll>& s){
    if(A < 1) return 0ll;
    if(A < 3) return 1ll;
    if(s.size() > A-1 && s[A-1] != -1) return s[A-1];
    ll h = (ll)log2(A);
    ll m = (ll)pow(2ll,h);
    ll p = (ll)A - m + 1ll;
    ll l = (p > (m/2ll)) ? (m-1ll)%mod : (m-1ll - ((m/2ll) - p))%mod;
    s[A] = ((comb[A-1ll][l]*find(l,s))%mod*find(A-l-1ll,s))%mod;
    return s[A]%mod;
}

int Solution::solve(int A) {
    A = A%mod;
    vector<ll> s(105, -1ll); ;
    comb[0][0] = 1ll;
    for(int i = 1 ; i < 105 ; i++)
    {
        comb[i][0] = comb[i][i] = 1ll;
        for(int j = 1 ; j < i ; j++) comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%mod;
    }
    return (int)(find((ll)A, s)%mod);
} 
 
 