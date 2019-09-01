int Solution::colorful(int A) {
    string B = to_string(A);
    unordered_set<long long int> sta;
    for(int i = 0;i<B.size();i++)
    {
        if(sta.find((long long int)(B[i]-'0')) == sta.end()) sta.insert((long long int)(B[i]-'0'));
        else return 0;
        long long int prod = (long long int)(B[i]-'0');
        for(int j = i+1;j<B.size();j++)
        {
            prod*=(long long int)(B[j]-'0');
            if(sta.find(prod) == sta.end()) sta.insert(prod);
            else return 0;
        }
    }
    return 1;
}
