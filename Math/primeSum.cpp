vector<int> Solution::primesum(int A) {
    vector<int> primes;
    vector<bool> temp(A,1);
    for(int i = 2; i <= A; i++){
        if(temp[i-2] == true){
            primes.push_back(i);
            for(int j = 2; j <= A/i; j++){
                temp[j*i - 2] = false;
            }
        }
    }
    int start = 0, end = primes.size()-1;
    vector<int> sol;
    while(start <= end){
        int sum = primes[start] + primes[end];
        if(sum == A){
            sol.push_back(primes[start]);
            sol.push_back(primes[end]);
            return sol;
        }
        else if(sum > A) end--;
        else start++;
    }
    return sol;
}


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
