typedef long long int ll;
int Solution::Mod(int A, int B, int C) {
    ll base = (ll)(A+(ll)C)%(ll)C;
    ll ans = 1ll;
    while(B > 0){
        if(B&1) ans = (ans*base)%(ll)C;
        base = (base*base)%(ll)C;
        B = B>>1;
    }
    return (int)ans%C;
}
