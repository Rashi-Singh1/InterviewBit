typedef long long int ll;
int Solution::hammingDistance(const vector<int> &A) {
    long long int ans = 0, n = A.size(), mod = 1000000007;
    long long int count;
    for(int i = 0 ; i < 32 ; i++){
        count=0;
        for(int j = 0 ; j < n ; j++){
            if(A[j] & (1 << i)) count = (count + 1ll)%mod;                //no of ones at the ith bit
        }
        ans = (ans+ ((count * (ll)(n-count)) % mod * 2ll) % mod) % mod; 
    }
    return (int)ans;
}

//notes
//No of ones for ith bit : count
//No of zeroes for ith bit : n - count
//No of relations from A to B : n(A) * n(B) : count * (n - count)
//multiply above result by 2, bcs we also need relation from B to A