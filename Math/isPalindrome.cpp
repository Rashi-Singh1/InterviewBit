#include <iostream>
// #include <cstdlib>
#include <bits/stdc++.h> 
#include<vector> 
using namespace std;
#define loop(x,start,end) for(int x = start; x < end; ++x)
#define ll long long int

/*not a very good sol*/
int isPalindrome(int A) {
	if(!A) return 1;
	if(A<0) return 0;
	int n=log10(A)+1;			//calculates the length of the integer
	if(n&1)
		A=(A/(int)pow(10,n-n/2))*(int)pow(10,n/2) + A%(int)pow(10,n/2);
	cout<<A<<endl;
	if(n&1) n=n-1;
	while(n){
		if(((A/(int)pow(10,n/2-1))%10)!=(A/(int)pow(10,n/2))%10) return 0;
		A=(A/(int)pow(10,n/2+1))*(int)pow(10,n/2-1) + A%(int)pow(10,n/2-1);
		n-=2;
	}
	return 1;
}

/* after reset using string*/
int Solution::isPalindrome(int A) {
    string b = to_string(A);
    for(int i = 0;i<b.size()/2;i++)
    {
        if(b[i] != b[b.size()-1-i]) return 0;
    }
    return 1;
}

int mysol1(int A)
{
	if(A > 0){
		int n = log10(A)+1;
		for(int i = 0;i<n/2;i++)
		{
			if((int)(A/pow(10,n-1-i))-((int)(A/pow(10,n-i)))*10 != ((int)(A/pow(10,i)))%10) return 0;
		}
		return 1;
	}
	else if(A == 0) return 1;
	else return 0;
}

int mysol2(int t)
{
	 if(t >= 0)
	 {
        string copy = to_string(t);
        for(int i = 0;i<(copy.size())/2;i++)
        {
            if(copy[i] != copy[copy.size()-1-i]) return 0;
        }
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	cout<<mysol(t)<<endl;
	return 0;
}