int Solution::evalRPN(vector<string> &A) {
    stack<int> numb;
    int ans = 0;
    int op1 = 0;
    int op2 = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == "*"){
            if(!numb.empty()) {
                op1 = numb.top();
                numb.pop();
            }
            if(!numb.empty()) {
                op2 = numb.top();
                numb.pop();
            }
            numb.push(op2*op1);
        }else if(A[i] == "/"){
            if(!numb.empty()) {
                op1 = numb.top();
                numb.pop();
            }
            if(!numb.empty()) {
                op2 = numb.top();
                numb.pop();
            }
            numb.push(op2/op1);
        }
        else if(A[i] == "-"){
            if(!numb.empty()) {
                op1 = numb.top();
                numb.pop();
            }
            if(!numb.empty()) {
                op2 = numb.top();
                numb.pop();
            }
            numb.push(op2-op1);
        }
        else if(A[i] == "+") {
            if(!numb.empty()) {
                op1 = numb.top();
                numb.pop();
            }
            if(!numb.empty()) {
                op2 = numb.top();
                numb.pop();
            }
            numb.push(op2+op1);
        }
        else numb.push(stoi(A[i]));
    }
    if(!numb.empty()) ans = numb.top();
    return ans;
}
