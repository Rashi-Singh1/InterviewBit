//to get largest co prime number, which is a factor of A, we remove the common factors of A and B from A, remaining part is factor of A and is coprime with B
int gcd(int A, int B){
    int l = min(A,B), m = max(A,B);
    A = m; B = l;    
    if(B == 0) return A;
    return gcd(B,A%B);
}

//remove largest common factor, which is GCD, till largest common factor becomes 1
int Solution::cpFact(int A, int B) {
    int g = gcd(A,B);
    while(g!=1){
        A/=g;
        g = gcd(A,B);
    }
    return A;
}

//way 2 : brute force
int gcd(int A, int B){
    int l = min(A,B), m = max(A,B);
    A = m; B = l;    
    if(B == 0) return A;
    return gcd(B,A%B);
}

int Solution::cpFact(int A, int B) {
    int ans = 1;
    for(int i = 1 ;i <= sqrt(A); i++){
        if(A%i == 0){
            int g = gcd(B, A/i);
            if(g == 1) return max(ans, A/i);
            else{
                g = gcd(B,i); 
                if(g == 1) ans = max(ans, i);
            }
        }
    }
    return ans;
}