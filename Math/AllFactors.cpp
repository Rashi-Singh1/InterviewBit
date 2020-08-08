//O(sqrt(A)) time and O(1) space (not considering buffer to return answer)
vector<int> Solution::allFactors(int A) {
    vector<int> sol;
    for(int i = 1; i <= sqrt(A); i++){
        if(A%i == 0) sol.push_back(i);
    }
    int size = sol.size();
    if(A > 0 && sol[size-1]*sol[size-1] == A) size--;
    for(int i = size-1; i >= 0; i--){
        sol.push_back(A/sol[i]);
    }
    return sol;
}


//This is not exactly O(sqrt(n)), bcs of sorting, to get rid of that, we can use extra space of O(no of factors/2)
vector<int> Solution::allFactors(int A) {
    if(A == 0)
    {
        vector<int> array;
        array.push_back(0);
        return array;
    }
    if(pow((int)sqrt(A),2) == A) 
    vector<int> array;
    array.push_back(1);
    if(A == 1)
    return array;
    for(int i = 2;i<=sqrt(A);i++)
    {
        if(A%i == 0) 
        {
            array.push_back(i);
            if(i!=sqrt(A)) array.push_back(A/i);
        }
    }
    array.push_back(A);
    sort(array.begin(),array.end());
    return array;
}

vector<int> Solution::allFactors(int A) {
    if(A == 0)
    {
        vector<int> array;
        array.push_back(0);
        return array;
    }
    // if(pow((int)sqrt(A),2) == A) 
    vector<int> array;
    vector<int> big;
    for(int i = 1;i<=sqrt(A);i++)
    {
        if(A%i == 0) 
        {
            array.push_back(i);
            if(i!=sqrt(A)) big.push_back(A/i);
        }
    }
    for(int i = big.size()-1;i>=0;i--)
    {
        array.push_back(big[i]);
    }
    return array;
}


