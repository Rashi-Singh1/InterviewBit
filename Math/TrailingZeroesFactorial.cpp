int Solution::trailingZeroes(int A) {
    int count = 0;
    int val = 5;
    while(val <= A){
        count+=(A/val);
        val*=5;
    }
    return count;
}


int Solution::trailingZeroes(int A) {
    int i = 5;
    int ans = 0;
    while(i<=A)
    {
        ans+=(A/i);
        i*=5;
    }
    return ans;
}
