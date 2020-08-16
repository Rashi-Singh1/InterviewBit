//O(N^2) time and O(1) space solution, TLE for larger test cases
string Solution::longestPalindrome(string A) {
    string ans;
    for(int i = 0 ; i < A.size(); i++){
        string temp(1,A[i]);
        for(int j = 1; j <= min(i,(int)A.size()-i-1); j++){
            if(A[i-j] == A[i+j]) temp = A[i-j] + temp + A[i+j]; 
            else break;
        }
        if(temp.size() > ans.size()) ans = temp;
        string temp2;
        for(int j = 1; j <= min(i,(int)A.size()-i); j++){
            if(A[i-j] == A[i+j-1]) temp2 = A[i-j] + temp2 + A[i+j-1];
            else break;
        }
        if(temp2.size() > ans.size()) ans = temp2;
    }
    return ans;
}