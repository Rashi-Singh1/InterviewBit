vector<int> Solution::sieve(int A) {
    vector<int> sol(A,1);
    vector<int> ans;
    for(int i = 2; i <= A; i++){
        if(sol[i - 2] == 1){
            ans.push_back(i);
            for(int j = 2; j <= A/i; j++){
                sol[j*i - 2] = 0;
            }
        }
    }
    return ans;
}
