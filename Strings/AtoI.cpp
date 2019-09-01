int Solution::atoi(const string A) {
    int i = 0;
    while(i<A.size())
    {
        if(A[i]==' ')
        {
            i++;
        }
        else break;
    }
    long long int ans = 0;
    bool neg = false;
    // cout<<i<<" "<<A[i]<<endl;
    if(i<A.size() && A[i] == '-')
    {
        neg = true;
        i++;
    }else if(i<A.size()&&A[i] == '+')
    {
        i++;
    }
    for(int j = i;j<A.size();j++)
    {
        int temp = (int)(A[j]-'0');
        // cout<<"temp  "<<temp<<endl;
        if(temp >=0 && temp <= 9)
        {
            ans = ans*10 + temp;
            // cout<<"ans   "<<ans<<endl;
            if(neg == false && ans > INT_MAX)
            {
                ans = INT_MAX;
                return ans;
            }else if(neg == true && (-1*ans) < INT_MIN)
            {
                ans = INT_MIN;
                return ans;
            }
        }
        else{
            break;
        }
    }
    if(neg == true)
    {
        return (int)(-1*(int)ans);
    }else{
        return (int)(ans);
    }
}

//after reset
int Solution::atoi(const string A) {
    int k = 0;
    while(k < A.size())
    {
        if(A[k] == ' ') k++;
        else break;
    }
    while(k < A.size())
    {
        if(A[k] == '0') k++;
        else break;
    }
    if(k>=A.size()) return 0;
    string B = A.substr(k);
    
    bool neg = false;
    if(B[0] == '-' || B[0] == '+') {
        if(B[0] == '-') neg = true;
        if(B.size()>1) B = B.substr(1);
    }
    long long int ans = 0;
    for(int i = 0;i<B.size();i++)
    {
        int temp = B[i]-'0';
        if(temp >=0 && temp <= 9) ans = ans*1ll*10 + (long long int)temp;
        else break;
        if(!neg && ans > INT_MAX) return INT_MAX;
        else if(neg && -1*ans < INT_MIN) return INT_MIN;
    }
    if(neg) return (int)-1*ans;
    return (int)ans;
}
