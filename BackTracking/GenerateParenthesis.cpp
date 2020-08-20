typedef long long ll;
void solve(vector<string>& ans, string temp, int* count, char* b, int n){
    if((ll)temp.size() == (ll)n*2ll){
        ans.push_back(temp);
        return;
    }
    if(count[0] > count[1]) return;                 //easy way to implement cond. that at no time, no. of ')' > no. of '('
    for(int i = 0 ; i < 2; i++){
        if(count[i] > 0){
            temp.push_back(b[i]);
            count[i]--;
            solve(ans, temp, count, b, n);
            temp.pop_back();
            count[i]++;
        }
    }
}

vector<string> Solution::generateParenthesis(int n) {
    int count[] = {n,n};
    char b[] = {'(',')'};
    vector<string> ans;
    string temp;
    solve(ans, temp, count, b, n);
    return ans;
}