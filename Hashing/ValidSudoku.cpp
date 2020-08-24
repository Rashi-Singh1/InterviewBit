int Solution::isValidSudoku(const vector<string> &A) {
    vector<string> col(9,"111111111"), box(9,"111111111");
    for(int i = 0 ; i < A.size(); i++){
        string row = "111111111";
        for(int j = 0 ; j < A[i].size(); j++){
            if(A[i][j]!='.'){
                int num = (int)(A[i][j]-'1');
                int box_no = 3*(int)(i/3) + (int)(j/3);
                if(!(row[num] > '0' && col[j][num] > '0' && box[box_no][num] > '0')) return 0;
                row[num] = '0';
                col[j][num] = '0';
                box[box_no][num] = '0';
            }
        }
    }
    return 1;
}