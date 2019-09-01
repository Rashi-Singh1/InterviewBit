//partial score, based on time complexity, idk what to do better
string divide(string A)
{
    string ans;
    int carry = 0;
    int j = 0;
    if(A.size() != 1)
    {
        string temp = A.substr(0,2);
        int num = stoi(temp);
        if(num < 20){
            carry = num-(((int)(num/2))*2);
            ans = to_string((int)(num/2));
            j = 2;
        }
    }
    for(int i = j;i<A.size();i++)
    {
        int numb = carry*10 + (int)(A[i]-'0');
        ans = ans + to_string(((int)(numb)/2));
        carry = numb - (((int)(numb/2))*2);
    }
    return ans;
}

int Solution::power(string A) {
    int i = 0;
    while(i < A.size())
    {
        if(A[i] == '0') i++;
        else break;
    }
    if(i < A.size()) A = A.substr(i);
    else return 0;
    if(A.size() == 0 || A=="0" || A=="1" ) return 0;
    while(A.size() > 1 || (A.size() == 1 && (int)(A[0]-'0') > 1))
    {
        if(((int)(A[A.size()-1])) % 2 == 1) return 0;
        else A = divide(A);
    }
    if(A.size() == 1 && A[0] == '1') return 1;
    else return 0;
}

//editorial
// string divide(string s,int &rem)
// {
//     int n=s.size(),i;
//     int carry=0;
//     string ret="";
//     for(i=0;i<n;i++){
//         int k=carry*10+s[i]-'0';
//         cout<<"k "<<k<<endl;
//         if(k%2!=0){
//             carry=1;
//         }
//         else{
//             carry=0;
//         }
//         k/=2;
//         if(ret=="" && k==0){
//             cout<<"i "<<i<<endl;
//             continue;
//         }
//         ret=ret+(char)(k+'0');
//     }
//     rem=carry;
//     cout<<ret<<endl;
//     return ret;
// }
// int Solution::power(string A) {
//     if(A=="1")return 0;
//     while(A!="1"){
//         //cout<<A<<endl;
//         int r=0;
//         A=divide(A,r);
//         if(r==1)return 0;
//     }
//     return 1;
// }
