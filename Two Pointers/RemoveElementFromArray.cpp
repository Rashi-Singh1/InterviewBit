int Solution::removeElement(vector<int> &A, int B) {
    int cur = -1;
    bool used = false;
    int count = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == B)
        {
            count++;
        }
        if(A[i] == B && used == false)
        {
            cur = i;
            used = true;
        }
        else if(A[i]!=B){
            if(cur == -1)
            {
                continue;
            }else{
                A[cur] = A[i];
                cur++;
            }
        }
    }
    //use erase from behind to get best case scenario
    int ans = A.size()-count;
    for(int i = 0;i<count;i++)
    {
        if(A.size()-1 >=0) A.erase(A.begin()+A.size()-1);
    }
    return ans;
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
