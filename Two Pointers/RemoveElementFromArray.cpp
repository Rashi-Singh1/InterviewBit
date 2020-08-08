int Solution::removeElement(vector<int> &A, int B) {
    int start = 0;
    for(int i = 0 ; i < A.size(); i++){
        if(A[i] == B) continue;
        else{
            int t = A[start];
            A[start++] = A[i];
            A[i] = t;
        }
    }
    A.erase(A.begin()+start, A.end());
    return start;
}

//after reset
int Solution::removeElement(vector<int> &A, int B) {
    int cur = -1;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == B) {
            cur = i;
            break;
        }
    }
    if(cur!=-1)
    {
        for(int i = cur+1;i<A.size();i++)
        {
            if(A[i]!=B)
            {
                A[cur] = A[i];
                cur++;
            }
        }
    }
    else{
        return A.size();
    }
    return cur;
}
