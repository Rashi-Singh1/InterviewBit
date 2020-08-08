string Solution::findDigitsInBinary(int A) {
    if(A == 0) return "0";
    string sol;
    while(A > 1){
        sol = (char)(A%2 + '0') + sol;
        A/=2;
    }
    if(A == 1) sol = (char)'1' + sol;
    return sol;
}
