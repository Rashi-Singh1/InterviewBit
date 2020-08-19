int Solution::isValid(string A) {
    stack<char> s;
    map<char,char> pair = {{')','('},{']','['},{'}','{'}};
    for(auto x : A){
        if(x == '(' || x == '[' || x == '{') s.push(x);
        else{
            if(s.empty()) return 0;
            if(pair[x] != s.top()) return 0;
            s.pop();
        }
    }
    if(s.empty()) return 1;
    return 0;
}
