//placement prep
//O(1) space sol
void Solution::setZeroes(vector<vector <int>> &A) {
    int row = A.size();
    if(row == 0) return;
    int col = A[0].size();
    if(col == 0) return;
    bool firstRow = false;
    for(int i = 0 ; i < row; i++){
        for(int j = 0; j < col; j++){
            if(A[i][j] == 0) {
                if(i == 0) firstRow = true;
                else A[i][0] = 10;
                A[0][j] = 10;
            }
        }
    }
    int root = A[0][0];
    for(int i = 1 ; i < row; i++){
        if(A[i][0] == 10) {
            for(int j = 0 ; j < col; j++) A[i][j] = 0;
        }
    }
    for(int j = 0; j < col ; j++){
        if(A[0][j] == 10){
            for(int i = 0 ; i < row; i++) A[i][j] = 0;
        }
    }
    if(firstRow){
        for(int i = 0 ; i < col; i++) A[0][i] = 0;
    }
}