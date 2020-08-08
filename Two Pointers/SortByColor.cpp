//without three pointers
void Solution::sortColors(vector<int> &A) {
    long long int ar[3] = {0}, k = 0;
    for(auto x : A) ar[x]++;
    
    for(int i = 0 ; i < 3; i++){
        for(long long int j = 0; j < ar[i]; j++){
            A[k++] = i;
        }
    }
}