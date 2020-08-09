//way 1: normal division
int divide(string A){
    if(A.size() == 0) return 0;
    if(A == "0" || A == "1") return 1;
    string q; int temp = 0;
    bool startZero = true;
    for(int i = 0 ; i < A.size(); i++){
        temp = temp*10 + (int)(A[i]-'0');
        if(temp/2 != 0 || (temp/2 == 0 && !startZero)) {
            startZero = false;
            q.push_back((char)((temp/2) + '0'));
        }
        temp = temp%2;
    }
    if(temp != 0) return 0;
    else return divide(q);
}

int Solution::power(string B) {
    if(B == "" || B=="1") return 0;
    return divide(B);
}

//way 2
//very good method to see if some number if 2^k or not
//take log2(num) and check if it is an integer
int Solution::power(string B) {
    long double A=stold(B);
    if(A==0|| A==1) return 0;
    return floor(log2(A))==ceil(log2(A))?1:0;
}

//good point : to see if fractional part is zero or not (i.e if no is integer or not)
//use ceil(num) == floor(num)