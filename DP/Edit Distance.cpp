int Solution::minDistance(string A, string B) {
    vector<int> dp((int)B.size()+1, 0), temp((int)B.size()+1, INT_MAX-1);
    if(A.size() == 0) return B.size();
    if(B.size() == 0) return A.size();
    for(int i = 0 ; i < A.size(); i++){
        dp[0] = i+1;
        for(int j = 0 ; j < B.size(); j++){
            int prev = (i == 0 ? j : temp[j]);
            if(A[i] != B[j]) prev++;
            dp[j+1] = min(prev, temp[j+1]+1);
            dp[j+1] = min(dp[j+1], dp[j]+1);
        }
        for(int j = 0 ; j <= B.size(); j++) temp[j] = dp[j];
    }
    return dp[(int)B.size()];
}

//Logic:
//consider bcab and babc
/*
*       b a b c
*       ------- 
*       0 1 2 3
*       -------
* b |1| 0 1 2 3 
* c |2| 1 1 2 2 
* a |3| 2 1 2 3
* b |4| 3 2 1 2
*
* dp[i][j] can take min of values dp[i-1][j]+1 (this stands for insertion to B or deletion from A), 
*                                 dp[i][j-1]+1 (this stands for insertion to A),
*                                 dp[i-1][j-1] if A[i] == B[j](that means at end of A[0<->i-1] and B[0<->j-1] is the same character) or dp[i-1][j-1]+1, if not equal 
*/