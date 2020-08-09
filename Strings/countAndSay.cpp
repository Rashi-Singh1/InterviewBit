string solve(string cur, int temp, int A ){
    if(temp == A) return cur;
    else {
        int count = 1; char trash = cur[0]; 
        string ans;
        for(int i = 1 ; i < cur.size(); i++){
            if(cur[i] == trash) count++;
            else{
                ans.push_back((char)(count+'0'));
                ans.push_back(trash);
                count = 1;
                trash = cur[i];
            }
        }
        ans.push_back((char)(count+'0'));
        ans.push_back(trash);
        return solve(ans,temp+1,A);
    }
}

string Solution::countAndSay(int A) {
    string ans;
    if(A < 1) return ans;
    return solve("1",1, A);
}

//after reset
string Solution::countAndSay(int A) {
    if(A == 1) return "1";
    string temp = countAndSay(A-1);
    string ans;
    for(int i = 0;i<temp.size();i++)
    {
        int trash = temp[i]-'0';
        int k = i;
        int count = 0;
        while((int)(temp[k]-'0') == trash)
        {
            count++;
            k++;
        }
        i = k-1;
        ans = ans+ to_string(count) + to_string(trash);
    }
    return ans;
}