//For placement - 

//pretty easy sol
int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] > 0 && A[i] <= A.size() && A[i]!=A[A[i]-1])
        {
            //swap
            int pos = A[i]-1;
            int t = A[i];
            A[i] = A[pos];
            A[pos] = t;
            
            //check for same index, bcs now swapped
            i--;
        }
    }
    for(int i = 0;i<A.size();i++)
    {
        if(A[i]!=(i+1)) return i+1;
    }
    return A.size()+1;
}

//khud ka
//Failing for larger test cases
int Solution::firstMissingPositive(vector<int> &A) {
    int ans = 1;
    int n = A.size();
    bool AllNonNeg = true;

    //To make sure saare neg and n se bade numbers 0 ho
    for(int i = 0; i<n ;i++)
    {
        if(A[i] <= 0 || A[i] > n) {
            A[i] = 0;
        }else{
            AllNonNeg = false;
        }
    }
    if(AllNonNeg == true) return ans;
    for(int i = 0;i<n ; i++)
    {
        //so that int exceed na kare (hence not +=n, bcs saare A[i] can be equal to n)
        //preserving current value and storing whether that (index + 1) value has occured
        if(A[i] > 0) A[((A[i])%n)-1] = A[((A[i])%n)-1]%n + (n*(A[i]%n));
    }
    for(int i = 0;i<n;i++)
    {
        //if that index+1 value not present, the value stored at the index would be btw 0 and n
        //problem
        //A[0] = n (intially causes problem)
        A[i]/=n;
    }
    for(int i = 0;i<n;i++)
    {
        if(A[i] == 0) return i+1;
    }
    return n+1;
}

//

//Editorial

int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] > 0 && A[i] <= A.size() && A[i]!=A[A[i]-1])     //A[i]!=A[A[i]-1] cond daalni zaroori h bcs i-- kar rhe the ke suppose i = 1 and A[i] = 20 h, jab swap karenge to A[19] = 20 ho jaega lekin A[1] = 1 ho gya ab is 1 ka kaam i.e A[0] = 1 karna h, to is i ke liye repeat karna h, but agar i = 1 and A[i] = 2, phir yahi repeat hota reh jaega, kyunki A[1] = 2 kar diya ab dobara i = 1 ke liye dekho, phir con satisfy ho gyi, phir i = 1 ke liye chalega and so on, to kahin pe rukna chahiye
        {
            int pos = A[i]-1;
            int temp = A[pos];
            A[pos] = A[i];
            A[i] = temp;
            i--;
        }
    }
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] != i+1) return i+1;
    }
    return A.size()+1;
}
