bool done;
void solve(vector<vector<char> >& A, vector<string>& row, vector<string>& col, vector<string>& box, int x, int y){
    if(A[x][y] != '.') {
        if(y < 8) solve(A, row, col, box, x, y+1);
        else if( x < 8) solve(A, row, col, box, x+1, 0);
        else done = true;
    }
    else for(int i = 0 ; i < 9; i++){
        int get_box =((int)(x/3))*3 + (int)(y/3);
        if(A[x][y] == '.' && row[x][i] > '0' && col[y][i] > '0' && box[get_box][i] > '0'){
            A[x][y] = char((i+1)+'0');
            row[x][i] = '0'; col[y][i] = '0'; box[get_box][i] = '0';
            if(y < 8) solve(A, row, col, box, x, y+1);
            else if( x < 8) solve(A, row, col, box, x+1, 0);
            else done = true;
            if(!done){
                row[x][i] = '1'; col[y][i] = '1'; box[get_box][i] = '1';
                A[x][y] = '.';
            }
        }
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    done = false;
    vector<string> row(9,"111111111");
    vector<string> col(9,"111111111");
    vector<string> box(9,"111111111");
    for(int i = 0 ; i < A.size(); i++){
        for(int j = 0 ; j < A[i].size(); j++){
            if(A[i][j] == '.') continue;
            row[i][(int)(A[i][j]-'0')-1] = 0;
            col[j][(int)(A[i][j]-'0')-1] = 0;
            int get_box = ((int)(i/3))*3 + (int)(j/3);
            box[get_box][(int)(A[i][j]-'0')-1] = 0;
        }
    }
    solve(A, row, col, box, 0, 0);
}