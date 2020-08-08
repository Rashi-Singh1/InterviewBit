int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() < 3) return A.size();
    int count = 1, trash = A[0], start = 1;
    for(int i = 1; i < A.size(); i++){
        if(A[i] == trash) {
            count++;
            if(count <= 2) {
                A[start++] = A[i];
            }
        }
        else{
            trash = A[i];
            A[start++] = A[i];
            count = 1;
        }
    }
    A.erase(A.begin() + start, A.end());
    return start;
}

//after reset
int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() < 3) return A.size();
    int cur = -1;
    long long int count = 0;
    int trash = A[0];
    for(int i = 1;i<A.size();i++)
    {
        if(A[i] == trash) count++;
        else count = 0;
        if(count == 2) {
            cur = i;
            break;
        }
        trash = A[i];
    }
    if(cur!=-1)
    {
        trash = A[cur];
        count = 1;
        for(int i = cur+1;i<A.size();i++)
        {
            if(A[i] == trash) count++;
            else count = 0;
            if(count < 2) {
                A[cur] = A[i];
                cur++;
            }
            trash = A[i];
        }
    }
    else return A.size();
    return cur;
}
