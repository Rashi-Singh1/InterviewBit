string mul(string A, char B){
    int c = 0, b = (int)(B-'0');
    string ans;
    for(int i = A.size()-1;i >=0;i--){
        int temp = ((int)(A[i]-'0'))*b;
        temp+=c;
        ans = (char)((temp%10)+'0') + ans;
        c = temp/10;
    }
    if(c > 0) ans = (char)(c+'0') + ans;
    return ans;
}

string add(string A, string B){
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int c = 0; string ans;
    for(int i = 0 ; i < min(A.size(),B.size()); i++){
        int temp = (int)(A[i]-'0') + (int)(B[i]-'0') + c;
        ans = (char)((temp%10)+'0') + ans;
        c = temp/10;
    }
    for(int i = min(A.size(),B.size()); i< A.size(); i++){
        int temp = (int)(A[i]-'0') + c;
        ans = (char)((temp%10)+'0') + ans;
        c = temp/10;
    }
    for(int i = min(A.size(),B.size()); i< B.size(); i++){
        int temp = (int)(B[i]-'0') + c;
        ans = (char)((temp%10)+'0') + ans;
        c = temp/10;
    }
    if(c > 0) ans = (char)(c+'0') + ans;
    return ans;
}

string Solution::multiply(string A, string B) {
    string ans = mul(A,B[B.size()-1]);
    for(int i = B.size()-2;i>=0;i--){
        string a = mul(A,B[i]);
        string zeroes(B.size()-1-i,'0');
        a+=zeroes;
        ans = add(ans,a);
    }
    reverse(ans.begin(),ans.end());
    while(ans.size() > 0 && ans[ans.size()-1] == '0') ans.pop_back();
    if(ans.size() == 0) return "0";
    reverse(ans.begin(),ans.end());
    return ans;
}