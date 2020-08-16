int Solution::numSetBits(unsigned int A) {
    int ans = 0;
    while(A > 0){
        ans++;
        A&=(A-1);
    }
    return ans;
}

int Solution::numSetBits(unsigned int A) {
    int ans = 0;
    while(A)
    {
        A = A&(A-1);		//makes the least significant 1 bit zero
        ans++;
    }
    return ans;
}
