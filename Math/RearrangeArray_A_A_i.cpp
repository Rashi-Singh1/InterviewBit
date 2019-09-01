void Solution::arrange(vector<int> &A) {
    for(int i = 0;i<A.size();i++)
    {
        A[i] = A[i] + ((A[A[i]]%A.size())*A.size());			//dont forget mod here bcs kuch values already changed hongi
    }
    for(int i = 0;i<A.size();i++)
    {
        A[i]/=A.size();
    }
    
}