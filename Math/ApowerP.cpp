int Solution::isPower(int A) {
    if(A == 1) return 1;
    for(int i = 1;i<=sqrt(A);i++)
    {
        float num = log(A)/log(i);
        num = num - (int)num;
        if(num == 0.000000) return 1;
    }
    return 0;
}

/*take care to use sqrt(A) for the for loop, think of it like while searching for log(A)/log(i), the min value can be 2, i.e. it can be 2, something ka square would make A, no lesser power of some integer would be valid. therefore, we can get 2 iff log(A)/log(sqrt(A)) giving 2 */