//after Reset
vector<int> Solution::primesum(int A) {
    vector<bool> isprime(A+1,true);
    vector<int> prime;
    for(int i = 2;i*i<=A;i++)
    {
        if(isprime[i])
        {
            for(int j = 2*i;j<=A;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(int i = 2;i<isprime.size();i++)
    {
        if(isprime[i])
            prime.push_back(i);
    }
    int start = 0;
    int end = prime.size()-1;
    vector<int> ans;
    while(start <= end)
    {
        if(prime[start] + prime[end] == A) {
            ans.push_back(prime[start]);
            ans.push_back(prime[end]);
            return ans;
        }else if(prime[start] + prime[end] > A) end--;
        else start++;
    }
}
