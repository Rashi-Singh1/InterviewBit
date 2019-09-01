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


int mysol(int A)
{
    if(A >= 0)
    {
        long long int B = 0;
        while(A)
        {
            B = B*10 + A%10;
            A/=10;
        }
        if(B > INT_MAX || B < INT_MIN)return 0;
        else return (int)B;
    }else{
        A = A* -1;
        long long int B = 0;
        while(A)
        {
            B = B*10 + A%10;
            A/=10;
        }
        if(B > INT_MAX || B < INT_MIN)return 0;
        else return -1 * (int)B;
    }
}