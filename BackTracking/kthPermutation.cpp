//normal backtracking sol gave TLE
string ans;
void solve(string temp, int A, int num, int* cur, vector<int>& count){
    bool alldone = true;
    for(auto x : count) if(x > 0) { alldone = false; break;}
    if(alldone){
        (*cur)++;
        if(*cur == num) ans = temp;
        return;
    }
    if(*cur > num) return;
    for(int i = 0 ; i < A; i++){
        if(count[i] > 0){
            count[i]--;
            temp.append(to_string(i+1));
            solve(temp, A, num, cur, count);
            count[i]++;
            for(int j = 0 ; j < (int)log10(i+1)+1; j++) temp.pop_back();
        }
    }    
}

string Solution::getPermutation(int A, int num) {
    ans = "";
    string temp;
    int cur = 0;
    vector<int> count(A,1);
    solve(temp, A, num, &cur, count);
    return ans;
}

//actual answer like rank of a dictionary

vector<long long int> fact;

long long int factorial(int num)
{
    if(fact.size() > num) return fact[num];
    if(num > 12) return (long long int)INT_MAX;
    int i = fact.size();
    for(int j = i;j<=num;j++)
    {
        fact.push_back(fact[j-1]*1ll*j);
    }
    return fact[num];
}

string Solution::getPermutation(int n, int k) {
    fact.clear();
    vector<bool> sta(n,false);
    fact = {1,1};
    string ans;
    int i = 1;
    int pos = n-1;
    bool flag = false;
    int cur = -1;
    bool done = false;
    while(pos>=0)
    {
        if(pos >= k || (int)(factorial(pos)) >= k)
        {
            if(cur != -1 && done)
            {
                ans.append(to_string(cur));
                sta[cur] = true;
                pos--;
            }
            else 
                for(int j = 1;j<=n;j++)
                {
                    if(sta[j] == true) continue;
                    else{
                        ans.append(to_string(j));
                        sta[j] = true;
                        pos--;
                        break;
                    }
                }
            cur = -1;
            flag = false;
            done = false;
        }
        else{
            
            k-=(int)(factorial(pos));
            int trash = cur;
            if(cur == -1) trash = 1;
            for(int j = trash;j<=n;j++)
            {
                if(sta[j] == true) continue;
                else{
                    cur = j;
                    if(flag == true) break;
                    flag = true;
                }
            }
            flag = false;
            done = true;
        }
    }
    return ans;
}