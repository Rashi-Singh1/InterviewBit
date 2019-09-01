vector<int> Solution::sieve(int A) {
    vector<bool> array (A+1,true);
    array[0] = array[1] = false;
    for(int i = 2;i*i<=A;i++)
    {
        if(array[i])
        {
            for(int j = 2*i;j<=A;j+=i)          //take care we r watching over all mutiples of i, i.e. 2i, 3i, etc.
            {
                array[j] = false;
            }
        }
    }
    vector<int> ans;
    for(int i = 2;i<=A;i++)
    {
        if(array[i])
            ans.push_back(i);
    }
    return ans;
}
