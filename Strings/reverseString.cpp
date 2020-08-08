string Solution::solve(string A) {
    int start = 0;
    while(start < A.size()){
        if(A[start] == ' ') start++;
        else break;
    }
    
    string temp = "";
    string ans;
    for(int i = start; i < A.size(); i++){
        if(A[i] == ' '){
            if(temp != "") ans = temp + " " + ans;
            temp = "";
        }else temp.push_back(A[i]);
    }
    if(temp!="") ans = temp + " " + ans;
    while(ans.size() > 0 && ans[ans.size()-1] == ' ') ans.pop_back();
    return ans;
}

//after reset
void Solution::reverseWords(string &A) {
    if(A.size() > 0){
        int i = 0;
        while(i < A.size())
        {
            if(A[i] == ' ') i++;
            else break;
        }
        string temp;
        string ans;
        for(int j = i;j<A.size();j++)
        {
            if(A[j]!=' ') temp+=A[j];
            else {
                if(!(temp == " " || temp == "")) ans = temp + " " + ans;
                temp = "";
            }
        }
        ans = temp + " " + ans;
        A = ans;
        i = A.size();
        while(i>0)
        {
            if(A[i-1] == ' ') i--;
            else break;
        }
        A = A.substr(0,i);
        i = 0;
        while(i < A.size())
        {
            if(A[i] == ' ') i++;
            else break;
        }
        A = A.substr(i);
    }
}