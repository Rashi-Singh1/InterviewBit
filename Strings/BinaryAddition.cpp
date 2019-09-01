int fullAdder(int a,int b, int* Cin)
{
    int carry = *Cin;
    *Cin = (a&b) | (b&carry) | (carry&a);
    return a^(b^carry);
}

string Solution::addBinary(string A, string B) {
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int Cin = 0;
    string ans;
    for(int i = 0;i<min(A.size(),B.size());i++)
    {
        int sum = fullAdder((int)(A[i]-'0'),(int)(B[i]-'0'),&Cin);
        ans+=to_string(sum);
    }
    if(A.size() > min(A.size(),B.size()))
    {
        for(int i = min(A.size(),B.size());i<A.size();i++)
        {
            int sum = fullAdder((int)(A[i]-'0'),0,&Cin);
            ans+=to_string(sum);
        }
    }
    if(B.size() > A.size())
    {
        for(int i = min(A.size(),B.size());i<B.size();i++)
        {
            int sum = fullAdder((int)(B[i]-'0'),0,&Cin);
            ans+=to_string(sum);
        }
    }
    if(Cin!=0) ans+=to_string(Cin);
    reverse(ans.begin(),ans.end());
    return ans;
}


//after reset
string FullAdder(int a, int b, int c)
{
    int ans = (a&b) | (b&c) | (c&a);
    ans = ans*10 + a^b^c;
    return to_string(ans);
}

string Solution::addBinary(string A, string B) {
    string ans;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int i = 0;
    int j = 0;
    int carry = 0;
    while(i < A.size() && j < B.size())
    {
        string temp = FullAdder((int)(A[i++]-'0'),(int)(B[j++]-'0'),carry);
        reverse(temp.begin(),temp.end());
        if(temp.size() == 1) carry = 0;
        else carry = temp[1]-'0';
        ans = temp[0] + ans;
    }
    while(i < A.size())
    {
        string temp = FullAdder((int)(A[i++]-'0'),0,carry);
        reverse(temp.begin(),temp.end());
        if(temp.size() == 1) carry = 0;
        else carry = temp[1]-'0';
        ans = temp[0] + ans;
    }
    while(j < B.size())
    {
        string temp = FullAdder(0,(int)(B[j++]-'0'),carry);
        reverse(temp.begin(),temp.end());
        if(temp.size() == 1) carry = 0;
        else carry = temp[1]-'0';
        ans = temp[0] + ans;
    }
    if(carry > 0) ans = to_string(carry) + ans;
    return ans;
}
