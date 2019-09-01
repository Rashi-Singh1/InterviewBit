int Solution::sqrt(int A) {
    long int start = 0;
    long int end = A;
    while(start<=end)
    {
        long int mid = (start+end)/2;
        if(mid*mid <= A && (mid+1)*(mid+1)>A) return (int)mid;
        else if(mid*mid < A)
        {
            start = mid+1;
        }
        else{

            end = mid-1;
        }
    }
}

//after reset
int Solution::sqrt(int B) {
    if(B < 2) return B;
    int start = 0;
    int end = B;
    long long int A = B;
    while(start <= end)
    {
        long long int mid = (start+ end)/2;
        if(mid*mid == A || (mid*mid < A && (mid+1)*(mid+1) > A)) return mid;
        else if(mid*mid > A) end = mid-1;
        else start = mid+1;
    }
}
