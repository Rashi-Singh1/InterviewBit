int Solution::solve(string A, string B) {
    vector<int> count(A.size()+1, 0);
    for(int b = 0 ; b < B.size(); b++){
        vector<int> count2(A.size()+1, 0);
        for(int a = 0 ; a < A.size(); a++){
            if(A[a] == B[b]) count2[a+1] = count[a]+1;
            else count2[a+1] = max(count2[a], count[a+1]);
        }
        for(int i = 0 ; i < A.size(); i++) count[i+1] = count2[i+1];
    }
    return count[A.size()];
}
//here we used count as prev vector and count2 as current vector
//so that after changing count2 bcs of char from B being considered at the moment, we can get proper value for count2(using count, which has values not disturbed from current character)