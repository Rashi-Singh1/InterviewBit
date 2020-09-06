int Solution::bulbs(vector<int> &A) {
    int count = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(count&1)
        {
            A[i] = A[i]^1;
        }
        if(A[i] == 0) count++;
    }
    return count;
}

//better solution
int Solution::bulbs(vector<int> &A) {
    int zero = 1;
    int ans = 0;
    for(auto x : A){
        if(zero && x == 0) {ans++; zero = !zero;}
        else if(!zero && x == 1) {ans++; zero = !zero;}
    }
    return ans;
}
