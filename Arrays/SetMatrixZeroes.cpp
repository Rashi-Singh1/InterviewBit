//showed correct answer in run, but not in submit
//O(1) space sol
void Solution::setZeroes(vector<vector<int> > &A) {
    bool isRow;
    bool isCol;
    int row = A.size();
    int col = A[0].size();
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            if(A[i][j] == 0)
            {
                A[i][0] = (A[i][0]%2) + 2;
                A[0][j] = (A[0][j]%2) + 2;
                if(i == 0 || j == 0)
                {
                    if(isRow == false) isRow = i ? false : true;
                    if(isCol == false) isCol = j ? false : true;
                }
            }
        }
    }
    
    //check for first col
    for(int i = 1;i < row;i++)
    {
        if(A[i][0]/2 == 1)
        {
            for(int j = 0; j<col;j++)
            {
                A[i][j] = 0;
            }
        }
    }
    
    //check for first row
    for(int i = 1;i < col; i++)
    {
         if(A[0][i]/2 == 1)
        {
            for(int j = 0; j<row;j++)
            {
                A[j][1] = 0;
            }
        }
    }
    
    if(A[0][0]/2 == 1)
    {
        if(isRow)
        {
            for(int i = 0; i < col;i++)
            {
                A[0][i] = 0;
            }
        }
        if(isCol)
        {
            for(int i = 0; i < row;i++)
            {
                A[i][0] = 0;
            }
        }
    }
}