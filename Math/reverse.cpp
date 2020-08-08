typedef long long int ll;
int Solution::reverse(int A) {
    long long int ans = 0;
    bool isNeg = A < 0;
    A = isNeg ? A*(-1) : A;
    while(A > 0){
        ans = ans*10ll + (ll)A%10ll;
        if(!isNeg && ans > INT_MAX) return 0;
        if(isNeg && -1ll*ans < INT_MIN) return 0;
        A/=10;
    }
    if(isNeg) return (int)(-1*ans);
    else return (int)ans;
}


int Solution::reverse(int A) {
    long long ret = 0;
    while(A){
        cout<<A%10<<endl;           //weirdly -ve number ka mod -ve de rha h and divide karne pe bhi
        ret *= 10;
        ret += A%10;
        A /= 10;
    }
    if(ret > INT_MAX || ret < INT_MIN)return 0;
    else return (int)ret;
}

//after reset
int Solution::reverse(int A) {
    if(A > INT_MAX || A< INT_MIN) return 0;
    else{
        long long int b = 0;
        while(A)
        {
            b = b*10+ A%10;
            A/=10;
            
        }
        if(b > INT_MAX || b < INT_MIN) return 0;
        return (int)b;
    }
}