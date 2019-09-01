int Solution::braces(string A) {
    stack<char> oper;
    bool need = false;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == '(') need = true;
        if(A[i] == ')')
        {
            if(oper.empty()) return 1;
            else {
                if(need == true) return 1;      //using this bcs of cases like (a)
                else oper.pop();
            }
            need = false;
        }
        else if(A[i] == '+' || A[i] == '*' || A[i] == '-' || A[i] == '/') {
            if(need == true) need = false;
            oper.push(A[i]);
        }
    }
    return 0;
}
