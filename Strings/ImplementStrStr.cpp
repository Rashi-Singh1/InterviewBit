//brute force : O(m*n)
int Solution::strStr(const string A, const string B) {
    if(A.size() == 0 && B.size() == 0) return 0;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == B[0])
        {
            int k = i+1;
            bool flag = false;
            for(int j = 1;j<B.size();j++)
            {
                if(A[k]!=B[j]) {
                    flag = true;
                    break;
                }
                else k++;
            }
            if(flag == false) return i;
        }
    }
    return -1;
}


//see KMP algo for O(n) time complexity