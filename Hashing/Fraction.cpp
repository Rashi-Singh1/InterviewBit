string Solution::fractionToDecimal(int num, int den) {
    long double ans = (long double)((long double)num/(long double)den);
    string temp = to_string(ans);
    string actual;
    for(int i = 0;i<temp.size();i++)
    {
        if(temp[i] == '.') {
            break;
        }
        actual.push_back(temp[i]);
    }
    long long int Num = (long long int)num;
    long long int Den = (long long int)den;
    Num = llabs(Num);
    Den = llabs(Den);
    Num = Num%Den;
    if(Num == 0) {
        if(actual.size() == 2 && actual[1] == '0' ) return "0";
        return actual;
    }
    actual.push_back('.');
    unordered_map<int,int> sta; //rem, index
    bool flag = false;
    while(Num)
    {
        if(sta.size() > 0 && sta.count(Num) > 0) {
            flag = true;
            break;
        }
        sta.insert(make_pair(Num,actual.size()));
        actual.push_back((char)((int)((long long int)(Num*1ll*10)/Den) + '0'));
        Num = (long long int)((long long int)(Num*1ll*10)%Den);
    }
    if(flag == true){
        temp = actual.substr(0,sta[Num]) + '(' + actual.substr(sta[Num]) + ')';
        return temp;
    }
    return actual;
}