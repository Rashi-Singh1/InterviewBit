string Solution::simplifyPath(string A) {
    int start = 0;
    int end = 0;
    stack<string> sta;
    for(int i = 0;i<A.size();i++)
    {
        int alph = (int)A[i]-'a';
        int alph2 = (int)A[i]-'A';
        if( (alph<=26 && alph>=0) || (alph2<=26 && alph2>=0) ) {
            start = i;
            end = i;
            int j = i+1;
            alph = (int)A[j]-'a';
            alph2 = (int)A[j]-'A';
            while( (alph<=26 && alph>=0) || (alph2<=26 && alph2>=0) )
            {
                end = j;
                j++;
                alph = (int)A[j]-'a';
                alph2 = (int)A[j]-'A';
            }
            string temp = "";
            temp.append(A,start,end-start+1);
            sta.push(temp);
            i = j-1;
            continue;
        }
        else{
            if(i < A.size()-1 && A[i] == '.' && A[i+1] == '.') if(!sta.empty()) sta.pop();
            else if(A[i] == '.') continue;
        }
    }
    string ans = "";
    while(!sta.empty()){
        ans = "/" + sta.top() + ans;
        sta.pop();
    }
    if(ans.size() == 0) return "/";
    return ans;
}
