string Solution::reverseString(string A) {
    stack<char> s;
    for(auto x : A){
        s.push(x);
    }
    string ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
