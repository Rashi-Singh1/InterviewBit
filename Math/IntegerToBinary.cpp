string Solution::findDigitsInBinary(int A) {
    string ans;
    if(A == 0)
        return "0";
    while(A)
    {
        ans+=to_string(A%2);
        A/=2;
    }
    reverse(ans.begin(),ans.end());
    int k = 0;
    while(k<ans.size())
    {
        if(ans[k] == '0')
            k++;
        else
            break;
    }
    ans.substr(k);
    return ans;
}
