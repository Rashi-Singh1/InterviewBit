int Solution::evalRPN(vector<string> &A) {
    stack<int> num;
    for(auto x : A){
        if(x == "+" || x == "-" || x == "*" || x == "/"){
            if(!num.empty()){
                int a,b;
                b = num.top();
                num.pop();
                if(!num.empty()){
                    a = num.top();
                    num.pop();
                    if(x == "+") num.push(a+b);
                    else if(x == "-") num.push(a-b);
                    else if(x == "*") num.push(a*b);
                    else if(b!=0) num.push(a/b);
                }
            }
        }else num.push(stoi(x));
    }
    if(!num.empty()) return num.top();
    return 0;
}