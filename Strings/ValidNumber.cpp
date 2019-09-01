int Solution::isNumber(const string A) {
    int signCount = 0, decimalCount = 0;
    bool flag = false;
    if(A.size() == 0) return 0;
    int l = 0;
    int start = 0;
    int end = A.size()-1;
    while(l < A.size())
    {
        if(A[l] == ' ') l++;
        else break;
    }
    if(l < A.size()) start = l;
    else return 0;
    l = A.size()-1;
    while(l>=0)
    {
        if(A[l] == ' ') l--;
        else break;
    }
    if(l >=0) end = l;
    else return 0;
    
    int blah = A[end]-'0';
    if(!(blah >=0 && blah <=9)) return 0;
    if(!(A[start] == '+' || A[start] == '-' || A[start] == '.' || (((int)(A[start]-'0')) >=0 && ((int)(A[start]-'0')) <=9))) return 0;
    if(A[start] == '.') {
        decimalCount = 1;
        flag = true;
    }
    int i = start + 1;
    for(i = start + 1;i<= end;i++)
    {
        int temp = (int)(A[i]-'0');
        if(temp>=0 && temp<=9) continue;
        else if(A[i] == 'e') break;
        else if(A[i] == '.'){
            if (flag == true) return 0;
            else flag = true;
        }
        else return 0;
    }
    if(i-1 >=0 )
    {
        int blah = A[i-1]-'0';
        if(blah >=0 && blah <=9) ;
        else return 0;
    }
    if(i+1 <= end)
    {
        if(!(A[0] == '+' || A[0] == '-' || (((int)(A[0]-'0')) >=0 && ((int)(A[0]-'0')) <=9))) return 0;
    }
    for(int j= i+2;j<=end;j++)
    {
        int temp = (int)(A[j]-'0');
        if(temp>=0 && temp<=9) continue;
        else if(A[j] == 'e' || A[j] == '.') return 0;
        else return 0;
    }
    return 1;
}


//koi logic nhi h isme, tatti ques