int Solution::romanToInt(string A) {
    map<string,int> sym = {{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
    int ans = 0;
    for(int i = 0 ; i < A.size(); i++){
        string temp(1,A[i]);
        if(i < A.size()-1){
            string temp2 = temp + A[i+1];
            if(sym[temp2] > 0) {
                ans+=sym[temp2];
                i++;
                continue;
            }
        }
        ans+=sym[temp];
    }
    return ans;
}

int Solution::romanToInt(string A) {
    vector<char> value = {'V','L','D','M'};
    vector<int> array = {5,50,500,1000};
    int ans = 0;
    int k = 0;
    while(k<A.size())
    {
        if(A[k] == ' ')
        {
            k++;
        }else{
            break;
        }
    }
    for(int i = k;i<A.size();i++)
    {
        if(A[i] == ' ')
            return ans;
        if(A[i] == 'I' || A[i] == 'X' || A[i] == 'C' && i < A.size()-1)
        {
            if(A[i]=='I')
            {
                switch(A[i+1])
                {
                    case 'V' : ans += 4; i++;
                    break;
                    case 'X' : ans +=9; i++;
                    break;
                    default : ans +=1;
                }
            }else if(A[i] == 'X')
            {
                switch(A[i+1])
                {
                    case 'L' : ans+=40; i++;
                    break;
                    case 'C' : ans +=90; i++;
                    break;
                    default : ans +=10;
                }
            }
            else{
                switch(A[i+1])
                {
                    case 'D' : ans+=400; i++;
                    break;
                    case 'M' : ans+=900; i++;
                    break;
                    default : ans+=100;
                }
            }
        }else{
            for(int j = 0;j<value.size();j++)
            {
                if(value[j] == A[i])
                {
                    ans+=array[j];
                }
            }
        }
        // cout<<A[i]<<" "<<ans<<endl;
    }
    return ans;
}

//after reset
int binarySearch(vector<string> &array, string temp)
{
    for(int i = 0;i<array.size();i++)
        if(array[i] == temp) return i;
    return -1;
}
int Solution::romanToInt(string A) {
   vector<string> array = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
   vector<int> value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
   int ans = 0;
   bool flag = false;
   for(int i = 0;i<A.size();i++)
   {
       if(i<A.size()-1){
           string temp = A.substr(i,2);
           int index = binarySearch(array,temp);
           if(index != -1){
               ans+=value[index];
               i++;
               if(i == A.size()-1) return ans;
           }else flag = true;
       }if(flag || i==A.size()-1)
       {
           string temp = A.substr(i,1);
           int index = binarySearch(array,temp);
           if(index != -1){
               ans+=value[index];
           }
       }
       flag = false;
   }
   return ans;
}
