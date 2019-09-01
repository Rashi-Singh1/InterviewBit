//naive, in fact not even memoized
int solve(int A)
{
    if(A<=2) return A;
    return solve(A-1)+solve(A-2);
}

int climbStairs(int A)
{
    return solve(A);
}


//O(n) time and O(1)
int b,c;

void solve(int A)
{
    if(A <=2 ) c = A;
    else{
        b = 1;
        c = 2;
        for(int i = 3;i<A;i++)
        {
            int t = c;
            c+=b;
            b = t;
        }
    }
}

int Solution::climbStairs(int A) {
    b = 0;
    c = 0;
    solve(A);
    return b+c;
}
