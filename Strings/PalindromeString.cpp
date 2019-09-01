bool alphanum(char a)
{
    int temp = a-'0';
    int temp2 = a-'a';
    int temp3 = a-'A';
    if(temp >=0 && temp <=9) return true;
    if(temp2 >=0 && temp2 < 26) return true;
    if(temp3 >=0  && temp3 < 26) return true;
    return false;
}
int Solution::isPalindrome(string A) {
    transform(A.begin(), A.end(), A.begin(), ::tolower); 
    int i = 0;
    int j = A.size()-1;
    int num = 0;
    while(i < j)
    {
        if(!alphanum(A[i])) i++;
        if(!alphanum(A[j])) j--;
        if(alphanum(A[i]) && alphanum(A[j]))
        {
            if(A[i] == A[j]) {
                i++;
                j--;
            }else return 0;
        }
    }
    return 1;
}
