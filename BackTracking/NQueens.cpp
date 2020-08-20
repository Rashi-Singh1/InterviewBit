typedef long long ll;
void solve(int n, vector<vector<string>>& ans, vector<string>& temp, string col, string ldiag, string rdiag, int x, int count){
    if(count == n){
        ans.push_back(temp);
        return;
    }
    if(x >= n) return;
    for(int y = 0; y < n; y++){
        int ld = (int)((ll)x+(ll)y), rd = (int)((ll)x-(ll)y + (ll)n - 1ll);
        if(col[y] > '0' && ldiag[ld] > '0' && rdiag[rd] > '0'){
            temp[x][y] = 'Q';
            col[y] = '0';
            ldiag[ld] = '0';
            rdiag[rd] = '0';
            solve(n, ans, temp, col, ldiag, rdiag, x+1, count+1);
            temp[x][y] = '.';
            col[y] = '1';
            ldiag[ld] = '1';
            rdiag[rd] = '1';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int n) {
    string col(n,'1'), ldiag((int)(2ll*(ll)n)-1ll, '1'), rdiag((int)(2ll*(ll)n)-1ll, '1'), trash(n,'.');
    vector<vector<string> > ans;
    vector<string> temp(n,trash);
    solve(n, ans, temp, col, ldiag, rdiag, 0, 0);
    return ans;
}