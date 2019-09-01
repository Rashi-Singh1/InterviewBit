int floorSearch(vector<int> &array, int start, int end , int x)
{
   while(start <= end )
   {
      if(x >= array[end]) return end;
      if(x < array[start]) return -1;
      int mid = (start+end)/2;
      if(array[mid] == x) return mid;
      else if(array[mid] < x)
      {
         if(mid+1 <=end && array[mid+1] > x)
            return mid;
         else
            // floorSearch(array,mid+1,end,x)
            start = mid+1;
      }else{
         if(mid-1 >= start && array[mid-1] <= x)
            return mid-1;
         else
            // floorSearch(array,start,mid-1,x);
            end = mid-1;
      }
   }
   return -1;
}

string Solution::intToRoman(int A) {
    vector<int> array = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    vector<string> value = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string ans;
    while(A)
    {
        int index = floorSearch(array,0,array.size()-1,A);
        if(index > -1){
            for(int i = 0;i<(A/(array[index]));i++)
            {
                ans += value[index];
            }
            A-=( (A/(array[index]))*array[index] );
        }
    }
    return ans;
}

//after reset
string Solution::intToRoman(int A) {
    vector<int> value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    vector<string> array = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string ans;
    for(int i = value.size()-1;i>=0;i--)
    {
        int trash = A/value[i];
        for(int j = 0;j<trash;j++)
        {
            ans+=array[i];
        }
        A-=trash*value[i];
    }
    return ans;
}
