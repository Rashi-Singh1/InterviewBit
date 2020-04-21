//For placement - 
int Solution::firstMissingPositive(vector<int> &A) {
    int size = A.size();
    if(size == 0) return 1;
    bool sizeP = false;
    for(int i = 0 ; i <  size; i++){
        if(A[i] == size) sizeP = true;
        if(A[i] >= size) A[i] = 0;
        if(A[i] < 0) A[i] = 0;
        A[i] = A[i] % size;
    }
    for(int i = 0 ; i < size; i++){
        int index = A[i]%size;
        A[index] = A[index]%size + size;
    }
    for(int i = 1; i < size; i++){
        A[i]/=size;
        if(A[i] == 0) return i;
    }
    if(sizeP) return size+1;
    else return size;
}

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
