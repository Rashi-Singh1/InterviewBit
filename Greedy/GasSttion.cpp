//way 1:
//Logic: 
//maintain gaspresent-gasneeded in ans and find its min
//the ans would be min+1, if ans at end of complete circle >=0 (if ans always pos, then starting from 0 alone can cover circuit)
//the ans would be min+1 for above case bcs after that min(-ve value), we have gas present at station > gas needed(ow ans would decrease even more)
typedef long long ll;
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    if(A.size() == 0) return 0;
    ll ans = (ll)A[0]-(ll)B[0], minAns = ans, min = 0;
    bool allPos = ans >= 0;
    for(int i = 1 ; i < B.size(); i++){
        ans += (ll)A[i]-(ll)B[i];
        if(ans < 0) allPos = false;
        if(ans < minAns) {minAns = ans; min = i;}
    }
    if(ans < 0) return -1;
    if(allPos) return 0;
    return (min+1)%(int)A.size();
}

//way 2:
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &used) {
    if(gas.size() == 0) return -1;
    long long int reservoir = 0;
    long long int end = 0;
    int index = 0;
    int i = 0;
    int trash = -1;
    while(i < gas.size())
    {
        if(i < index) i = index;
        if(trash!=i) reservoir+=(long long int)(1ll*gas[i]-1ll*used[i]);
        trash = i;
        if(reservoir < 0)
        {
            reservoir+=(long long int)(1ll*used[index]-1ll*gas[index]);
            end+=(long long int)(1ll*gas[index]-1ll*used[index]);
            index++;
        }
        else{
            i++;
        }
    }
    if(reservoir+end < 0) return -1;
    else return index;
}
    