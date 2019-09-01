//naive solution, not time effective
int trash;
string ans;
vector<bool> sta;
bool flag;
void solve(int n, int k, int size)
{
    if(size == n){
        trash--;
        if(trash == 0) flag = true;
        return;
    }
    for(int i = 0;i<sta.size();i++)
    {
        if(sta[i] == false) {
            sta[i] = true;
            ans.append(to_string(i+1));
            solve(n,k,size+1);
            sta[i] = false;
            if(flag == true) break;
            ans.pop_back();
            if(i>=9) ans.pop_back();
        }
    }
}

string Solution::getPermutation(int n, int k) {
    if(n == 0 || k == 0) return "";
    trash = k;
    sta.clear();
    for(int i = 0;i<n;i++) sta.push_back(false);
    ans = "";
    int i = 1;
    flag = false;
    while(trash)
    {
        sta[i-1] = true;
        ans = to_string(i);
        solve(n,k,1);
        sta[i-1] = false;
        i++;
    }
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