typedef long long int ll;
ll mod = 1e9 + 7;

void fact(vector<int>& A, int num){
    for(int i = A.size(); i <= num; i++){
        A.push_back(( A[A.size() - 1] * (i % mod)) % mod);
    }
}

int power(vector<int>& A, int num){
    if(num < 1) return 1;
    if(num < A.size()) return A[num];
    for(int i = A.size(); i <= num; i++){
        A.push_back(( A[A.size() - 1] * 2) % mod);
    }
    return A[num];
}

//x^y mod m
int power2(int x, int y, int m){
    ll ans = 1;
    ll base = x;
    while(y > 0){
        if(y&1) ans = (ans*(base%m))%m;
        base = (base*base)%m;
        y/=2ll;
    }
    return (int)ans;
}

int Solution::solve(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    vector<int> fac = {1,1};
    vector<int> powe = {1, 2};
    fact(fac, A-B.size());
    ll sol = fac[A-B.size()], den = 1;
    for(ll i = 1; i < B.size(); i++){
        sol = (sol*power(powe, B[i]-B[i-1]-2))%mod;
        den = (den * fac[B[i]-B[i-1]-1])%mod;
    }
    den = (den * fac[B[0]-1])%mod;
    den = (den * fac[A-B[B.size()-1]])%mod;
    sol = (sol * power2(den, mod-2, mod))%mod;
    return sol;
}

//check below for inverse modulo
//bcs (a/b) mod c != ((a mod c)/(b mod c)) mod c
/*
* a/b mod c -> a * b^-1 mod c
* b * b^-1 mod c = 1 mod c
* therefore, x such that b x mod c = 1, is b^-1 mod c
* to find b^-1 mod c, use euclidean algo (code lengthy)    O(logc)
* however, when c is prime, can use fermat's little theorem
* a^p - a = k*p, where p is prime
* a^p = k*p + a -> a^p = a (mod p)
* a^(p-1) = 1 (mod p)
* a * a^(p-2) = 1 (mod p) which is same as (a * a^(p-2)) mod p = 1
* therefore, a^-1 mod p = power(a, p-2) % p
* this is done by function power2
*/

//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/


//Actual logic of code: 
//for the given example, can move to 2 | 4 | 7 | 9 | 10 | 12 in the beginning
// 1 2 3 4 5 6 7 8 9 10 11 12
//     x         x      x
//there are 4 groups formed
//out of 9 seats left (which denote the order of visiting cities)
// _ _ _ _ _ _ _ _ _

//divide the 9 seats into groups of given sizes in (9! / (2! * 4! * 2! * 1!)) ways 
//furthermore, the number of ways of going to cities from a group : 
//if group in middle : if there are 4 seats, the first three seats, each has 2 choices (leftmost, rightmost city), last is fixed
//therefore, 2^(4-1)
//if at end, then only 1 way, for the above example, order for 1,2 can only be 2 -> 1