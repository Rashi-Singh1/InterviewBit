typedef long long int ll;
ll mod = 1000000007;
int Solution::solve(int A) {
    if(A < 1) return 0; if(A == 1) return 1;
    ll full = (ll)log2(A), base = (ll)(1ll<<full);
    return (((full*(base/2ll))%mod + (((ll)A + 1ll)%mod - base)%mod)%mod + solve((int)((ll)A-base)))%mod;
}


// Logic:
// for example - A = 13
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// upto, log2(13) = 3 decimal places, we have all the numbers
// i.e. for each ith place we have (1<<3)/2 = 8/2 = 4 ones (for 2^0, 2^1, 2^2 positions)
// i.e. till now, a total of 4*3 1s

//additionally add 13 + 1 - 8 ones (neeche vale numbers ke MSB)

// 1    000
// 1    001
// 1    010
// 1    011
// 1    100
// 1    101

//now repeat the process for 13 - 8 = 5
//don't forget to add the ending condition
//i.e. if A <= 0 return 0 and if A == 1 return 1