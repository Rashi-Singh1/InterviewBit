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
