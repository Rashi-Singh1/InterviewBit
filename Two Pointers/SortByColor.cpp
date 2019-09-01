void Solution::sortColors(vector<int> &A) {
   int array[3] = {0,0,0};
   for(int i = 0;i<A.size();i++)
   {
       array[A[i]]++;
   }
   int j = 0;
   for(int i = 0;i<A.size();i++)
   {
       if(j < 3 && array[j] > 0) {
           A[i] = j;
           array[j]--;
       }else {
           j++;
           i--;
       }
   }
}
