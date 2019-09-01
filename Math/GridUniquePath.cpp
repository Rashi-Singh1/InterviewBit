/*My solution*/
int dpSol(int A, int B) {
    int array[A][B];
    for(int i = 0;i<A;i++)
    {
        array[i][0] = 1;
    }
    for(int i = 0;i<B;i++)
    {
        array[0][i] = 1;
    }
    array[0][0] = 1;
    for(int i = 0;i<A;i++)
    {
        for(int j = 0;j<B;j++)
        {
            if(i==0 || j==0)
            {
                //
            }
            else{
                array[i][j] = -1;
            }
        }
    }
    for(int i = 1;i<A;i++)
    {
        for(int j = 1;j<B;j++)
        {
            array[i][j] = array[i-1][j] + array[i][j-1];
        }
    }
    return array[A-1][B-1];
}

//After reset
int Solution::uniquePaths(int A, int B) {
   int array[A][B];
   for(int i = 0;i<A;i++)
   {
       for(int j = 0;j<B;j++)
       {
           if(i == 0 || j == 0) array[i][j] = 1;
           else array[i][j] = 0;
       }
   }
   for(int i = 1;i<A;i++)
   {
       for(int j = 1;j<B;j++)
       {
           array[i][j] = array[i-1][j] + array[i][j-1];
       }
   }
   return array[A-1][B-1];
}

//After reset
int Solution::uniquePaths(int A, int B) {
    long long int ans = 1;
    int Max = max(A,B);
    for(int i = Max;i<=A+B-2;i++)
    {
        ans *= i;
        ans/=(i-Max+1);
    }
    return (int)ans;
}

/*Editorial*/
int sol(int A, int B)
{
    long long int ans = 1;
    for(int i = A;i<A+B-1;i++)
    {
        ans*=i;
        ans/=i-A+1;
    }
    return ans;
}


/*

    m+n-2   m+n-3   m+n-4 ............  n           ****n-1  .......  m   m-1  ............... 1*****
  ______________________________________________________________________________________________________

    m-1     m-2     m-3                1            ****n-1                                    1*****


    Think of it like you only need to calculate the left of the tabbbed portion bcs baaki ka kat pit jaega
    So each entry in denominator is corresponding to (itself + n-1) value in numerator

*/