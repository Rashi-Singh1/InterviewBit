//way 1: O(n) time and O(n) space
int solve(int A, vector<int>& m){
    if(A < 3) return A;
    if(m[A] != -1) return m[A];
    return (m[A] = solve(A-1, m) + solve(A-2, m));
}

int Solution::climbStairs(int A) {
    vector<int> m(A+1, -1);
    return solve(A, m);
}


//way 2: O(n) time and O(1) space
int Solution::climbStairs(int A) {
    int a = 0, b = 1, c = 1;
    for(int i = 0 ; i < A; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}
