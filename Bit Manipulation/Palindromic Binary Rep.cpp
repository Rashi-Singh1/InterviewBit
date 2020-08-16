#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

auto getBinary(int num){
    return bitset<18>(num);
}

int formAnswer(int A, ll bits, ll possible){
    if(bits <= 0 || A <= 1) return 0;
    int sub = A <= (possible/2) ? 0 : possible/2;
    int temp = formAnswer(A-sub, bits-2, 1<<((bits-1)>>1));
    if(A <= possible/2) return (int)(temp<<1);
    else return (int)(temp<<1 | 1 | 1<<(bits-1));
}

int solve(int A){
    if(A == 1) return 1;
    A-=1;
    ll bits = 2, possible = 1<<((bits-1)>>1);
    while(A >= 0 && (ll)A >= possible){
        A-=possible;
        bits++;
        possible = 1<<((bits-1)>>1);
    }
    if(A < 0) return 1;                                     //think of this later
    else if(A == 0) return (int)((1<<(bits-1))-1);
    int temp = formAnswer(A, bits-2, possible);
    return (int)(1 | 1<<(bits-1) | temp<<1);
}

int main(int argc, char const *argv[])
{
    cout<<getBinary(solve(18))<<endl;
    cout<<getBinary(93)<<endl;
    cout<<getBinary(solve(1000))<<endl;
    cout<<getBinary(250671)<<endl;
    return 0;
}
