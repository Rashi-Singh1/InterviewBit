void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    reverse(A.begin(), A.end());
    for(int i=0; i<n; i++){
        for(int j=0; i+j <n; j++){
             swap(A[i][i+j], A[i+j][i]);
        }
    }
}

//after Reset
void Solution::rotate(vector<vector<int> > &A) {
    reverse(A.begin(),A.end());
    for(int i = 0;i<A.size();i++)
    {
        for(int j = i+1;j<A[0].size();j++)
        {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}
