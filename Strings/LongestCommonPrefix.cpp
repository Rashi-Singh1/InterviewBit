
/*sol1*/
//binary search method using search on the length of the prefix
string Solution::longestCommonPrefix(vector<string> &A) {
    string ans;
    if(A.size() == 0)
        return ans;
    int minSize = A[0].size();
    for(int i = 1;i<A.size();i++)
    {
        if(minSize > A[i].size()) minSize = A[i].size();
    }
    int start = 0;
    int end = minSize;
    while(start<=end)
    {
        int mid = (start+end)/2;
        string temp = A[0].substr(0,mid);
        bool flag = false;
        for(int i = 1;i<A.size();i++)
        {
            if(A[i].substr(0,mid)!=temp)
            {
                flag = true;
                end = mid-1;
                break;
            }
        }
        if(flag == false)
        {
            ans = A[0].substr(0,mid);
            start = mid + 1;
        }
    }
    return ans;
}

/*sol2*/
//check char by char
string Solution::longestCommonPrefix(vector<string> &A) {
    string ans;
    if(A.size() == 0)
        return ans;
    int minSize = A[0].size();
    for(int i = 1;i<A.size();i++)
    {
        if(minSize > A[i].size()) minSize = A[i].size();
    }
    for(int i = 0;i<minSize;i++)
    {
        char temp = A[0][i];
        for(int j = 0;j<A.size();j++)
        {
            if(A[j][i] != temp)
                return ans;
        }
        ans +=temp;
    }
    return ans;
}

//after reset
string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.size() == 0) return "";
    
    int minL = A[0].size();
    for(int i = 1;i<A.size();i++) 
        minL = min(minL,(int)(A[i].size()));
        
    string ans;
    for(int i = 0;i<minL;i++)
    {
        char temp = A[0][i];
        for(int j = 1;j<A.size();j++)
        {
            if(A[j][i] != temp) return ans;
        }
        ans+=temp;
    }
    return ans;
}
