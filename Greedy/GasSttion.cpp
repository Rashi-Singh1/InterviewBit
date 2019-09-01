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
    