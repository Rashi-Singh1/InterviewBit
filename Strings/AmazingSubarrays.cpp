int Solution::solve(string A) {
    long long int sum = 0;
    transform(A.begin(), A.end(), A.begin(), ::tolower); 
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        {
            sum  = (sum + (A.size()-i)%10003)%10003;
        }
    }
    return sum%10003;
}
