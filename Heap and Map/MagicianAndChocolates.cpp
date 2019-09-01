int Solution::nchoc(int A, vector<int> &B) {
    long long int Mod = 1000000007;
    long long int ans = 0;
    map<int, int > myMap;
    for(int i = 0;i<B.size();i++)
    {
        myMap[B[i]]++;
    }
    for(int i = 0;i<A;i++)
    {
        int val = myMap.rbegin()->first;
        ans = (( (long long int)val)%Mod + ans)%Mod;
        if(myMap.rbegin()->second > 1) (myMap.rbegin()->second)--;
        else myMap.erase(val);
        myMap[(int)val/2]++;
    }
    return (int)(ans%Mod);
}