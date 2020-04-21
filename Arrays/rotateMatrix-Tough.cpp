//placement prep
void Solution::rotate(vector<vector<int> > &A) {
    int row = A.size();
    if(row == 0) return;
    int col = A[0].size();
    if(col == 0) return;
    for(int i = 0 ; i < row/2; i++){
        for(int j = 0 ; j < col; j++){
            int temp = A[i][j];
            A[i][j] = A[row-1-i][j];
            A[row-1-i][j] = temp;
        }
    }
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col; j++){
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}


class Solution {
public:
     void rotate(vector<vector<int> > &matrix) {

        int len = matrix.size();
        for (int i = 0; i < len / 2; i++) {
            for (int j = i; j < len - i - 1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[len - j - 1][i];
            matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
            matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
            matrix[j][len - i - 1] = tmp;
            }
        }
    }
};

