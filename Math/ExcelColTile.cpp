//my solution - worked
string Solution::convertToTitle(int A) {
    string ans;
    while(A > 0){
        if(A%26 == 0){
            ans = 'Z' + ans;
            A-=26;
        }else{
            ans = (char)('A' + (A%26 - 1)) + ans;
            A-=A%26;
        }
        A/=26;
    }
    return ans;
}

//after reset
string Solution::convertToTitle(int a) {
    if(a <= 0)
        return "";
    string ans;
    while(a>0)
    {
        int temp = (64 + (int)a%26);
        if(a%26!=0 ) ans=((char)temp) + ans;
        else ans='Z' + ans;
        if(a > 0 && a <= 26) break;
        if(a%26!=0) a = a - a%26;
        else a-=26;
        a/=26;
    }
    return ans;
}

//think of it like for BAQTZ
/*
    943566 = 26 + 20*26 + 17*26*26 + 1*26*26*26 + 2*26*26*26*26
             Z    T       Q          A            B
    we need to calculate mod, then mod subtract karke, pure ko 26 se divide karna h, mod main 0 ki bajae 26 vali cond daalni h
*/