vector<int> Solution::maxone(vector<int> &A, int B) {
    queue<int> zeroes;
    if(B < 0) B = 0;
    int start = 0;
    int end = 0;
    int count = 0;
    int i = 0;
    int s = 0;int e = 0;
    vector<int> ans;
    while(i<A.size())
    {
        if(A[i] == 0) {
            count++;
            zeroes.push(i);
        }
        if(A[i] == 1 || count <= B) {
            end++;
        }
        else if(count > B)
        {
            start = zeroes.front()+1;
            end = i;
            count--;
            zeroes.pop();
        }
        i++;
        if(end-start > e-s)
        {
           if(A[end] == 0){
                if(end-start-1 > e-s){
                    s = start;
                    e = end-1;
                }
            }
            else{
                s = start;
                e = end;
            }   
        }
    }
    if(end-start > e-s)
    {
        if(A[end] == 0){
            if(end-start-1 > e-s){
                s = start;
                e = end-1;
            }
        }
        else{
            s = start;
            e = end;
        }   
    }
    for(int j = s;j<=e;j++)
        if(j < A.size()) ans.push_back(j);
    return ans;
}
