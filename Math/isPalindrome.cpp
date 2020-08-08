#define loop(x,start,end) for(int x = start; x < end; ++x)
#define ll long long int

int Solution::isPalindrome(int A) {
    if(A < 0) return 0;
    long long int n = (int)(log(A)/log(10)) + 1, p = pow(10, n-1);
    for(int i = 0; i <= n/2; i++){
        if(A%10 == A/p) {
            A = A%p;
            A = A/10;
			p = p/100 > 0 ? p/100 : 1;		//bcs we are using A%p and p can't be zero and pow function gives >= 1 output
        }
        else return 0;
    }
    return 1;
}

//notes:
//n : size
//for 12121, p : 10000
//A%10 : gives last digit
//A/p : gives first digit
//A = A%p : 12121 -> 2121
//A = A/10 : 2121 -> 212

/*using string*/
int Solution::isPalindrome(int A) {
    string b = to_string(A);
    for(int i = 0;i<b.size()/2;i++)
    {
        if(b[i] != b[b.size()-1-i]) return 0;
    }
    return 1;
}