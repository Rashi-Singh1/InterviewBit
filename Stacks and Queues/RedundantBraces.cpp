int Solution::braces(string A) {
    stack<char> s;
    for(auto x : A){
        if(x == '(' || x == '+' || x == '-' || x == '*' || x == '/') s.push(x);
        else if(x == ')'){
            if(s.empty()) return 1;
            bool red = true;
            while(!s.empty() && s.top() != '('){
                s.pop();
                red = false;
            }
            if(red == true || s.empty()) return 1;
            else s.pop();
        }
    }
    while(!s.empty()){
        if(s.top() == '(') return 1;
        s.pop();
    }
    return 0;
}
