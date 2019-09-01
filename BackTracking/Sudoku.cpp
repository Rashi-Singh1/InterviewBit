bool isSafe(vector<vector<char> >& A, int row, int col, int val)
{
    //checking in a row
    for (int i = 0; i < 9; ++i)
    {
        if(A[row][i] == (char)(val + '0')) return false;
    }
    //checking in a col
    for (int i = 0; i < 9; ++i)
    {
        if(A[i][col] == (char)(val + '0')) return false;
    }
    //checking in a block
    for(int i = (3*(int)(row/3)); i < 3*(((int)(row/3))+1) ; i++)
    {
        for(int j = (3*(int)(col/3)); j < 3*(((int)(col/3))+1) ; j++)
        {
            if(i!=row && j!=col && A[i][j] == (char)(val + '0')) return false;
        }
    }
    return true;
}

bool done;
void solve(vector<vector<char> >& A, int row, int col)
{
    if(A[row][col] == '.')
    {
        for(int i = 1;i<=9;i++)
        {
            if(isSafe(A,row,col,i) == true)
            {
                // print(A); cout<<endl;
                A[row][col] = (char)(i + '0');
                if(col<8) solve(A,row,col+1);
                else if(row < 8) solve(A,row+1,0);
                else done = true;
            }
            if(done == true) break;
            else A[row][col] = '.';
        }
    }
    else{
        if(col<8) solve(A,row,col+1);
        else if(row < 8) solve(A,row+1,0);
        else done = true;
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    done = false;
    solve(A,0,0);
}


