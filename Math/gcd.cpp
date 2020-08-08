int Solution::gcd(int A, int B) {
    int l = min(A,B), m = max(A,B);
    A = m; B = l;                       //make A as max value of A,B and vice-versa
    if(B == 0) return A;
    return gcd(B,A%B);
}

//O(log(A+B)) roughly
//Based on Euclidean algo division vali
int euclideanAlgo(int A, int B)
{
	if(A == 0 && B!=A) return B;
	if(B == 0 && A!=B) return A;
	if(A%B == 0) return B;
	else if(B%A == 0) return A;
	return euclideanAlgo(B,A%B);
}

//After reset
int Solution::gcd(int A, int B) {
    if(B == 0) return A;
    else if(A%B == 0) return B;
    else if(A == 0) return B;
    else if(B%A == 0) return A;
    else return gcd(B,A%B);
}

/*My previous ganda vala way*/
//O(min(A,B))
//Based on Euclidian algo subtraction vali
int Solution::gcd(int A, int B) {
    if(A == 0 && B!=0) return B;
    else if(A!=0 && B==0 ) return A;
    if(A%B == 0) return B;
    else if(B%A==0) return A;
    else{
        int ans = B;
        while(!(A%ans == 0 && B%ans == 0) && ans >=1)
        {
            //cout<<ans<<endl;
            if(A%ans == 0 && B%ans == 0) return ans;
            if(A > B) {
                ans = A-B;
                A = A-B;
            }
            else {
                ans = B-A;
                B = B-A;
            }
        }
        return ans;
    }
}