
//after reset - brute force O(n) solution
int Solution::pow(int x, int n, int d) {
    if(x == 0) return 0;
    else{
        if(n == 0) return 1%d;
        else{
            int ans = 1;
            x+=d;
            for(int i = 0;i<n;i++)
            {
                ans = ((ans%d)*(x%d))%d;
            }
            return ans%d;
        }
    }
}

//after reset O(LogN) solution
string binary(int n)
{
    string ans;
    while(n)   
    {
        ans = (to_string(n%2))+ ans; 
        n/=2;
    }
    return ans;
}

int Solution::pow(int x, int n, int d) {
    if(x == 0) return 0;
    else{
        if(n == 0) return 1%d;
        else{
            x+=d;
            x%=d;
            string bin = binary(n);
            reverse(bin.begin(),bin.end());
            long long int rem = x%d;
            long long int ans = 1%d;
            for(int i = 0;i<bin.size();i++)
            {
                if(bin[i] == '1')
                {
                    ans = (ans * rem)%d;
                }
                rem = (rem*rem)%d;
            }
            return (int)(ans%d);
        }
    }
   
}

/*
consider the example 
x = 3
n = 23
d = 2

i.e. we need to find (3^23)%2
brute force method takes O(n), bcs we would ultimately multiply 3 n times

binary representation of 23 is 10111
altho length of binary representation is more than length of decimal representation
but pehle 23 baar multiply karna padta, ab bin.size(), i.e. 5 here times karna padega bcs:
we can find it as

            4        2       1       0
 23   =    2    +   2   +   2    +  2
3         3


            4       2       1       0
 23   =    2       2       2       2
3         3   *   3   *   3   *   3

hence the name squarying method

*/