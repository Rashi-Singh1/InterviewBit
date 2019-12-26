//For placement - 

vector<int> Solution::plusOne(vector<int> &A) {
   reverse(A.begin(),A.end());
   int i = 0;
   while(A[i] == 9) A[i++] = 0;
   if(i < A.size())
   {
       A[i]++;
   }
   else{
       A.push_back(1);
   }
   for(int i = A.size()-1;i>=0;i--)
   {
       if(A[i] == 0) A.erase(A.begin() + i);
   }
   reverse(A.begin(),A.end());
   return A;
    
}

//

vector<int> Solution::plusOne(vector<int> &A) {
    int index = A.size()-1;
    int flag = 0;
    for(int i = A.size()-1;i>=0;i--)
    {
        if(A[i] == 9) {
            A[i] = 0;
            flag = 1;
        }
        else{
            index = i;
            break;
        }
    }
    if(flag == 1 && index == A.size()-1) {
        //
    }
    else A[index] = A[index]+1;
    vector<int> answer;
    if(flag == 1 && index == A.size()-1) answer.push_back(1);
    int temp = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(flag == 1 && index == A.size()-1){
            temp = 1;
            answer.push_back(A[i]);
        }
        else if(A[i] == 0 && temp == 0 )
        {
            //
        }else if (A[i]!=0)
        {
            temp = 1;
            answer.push_back(A[i]);
        }
        else{
            temp = 1;
            answer.push_back(A[i]);
        }
    }
    return answer;
}

//after Reset
vector<int> Solution::plusOne(vector<int> &A) {
    int i = A.size()-1;
    bool all9 = false;
    while(i>=0)
    {
        if(A[i] == 9)
        {
            if(i == 0) all9 = true;
            A[i] = 0;
            i--;
        }else{
            break;
        }
    }
    if(i>=0 && all9 == false) A[i]+=1;
    if(all9 == true) A.insert(A.begin(),1);
    i = 0;
    while(i<A.size())
    {
        if(A[i] == 0)
            i++;
        else
            break;
    }
    if(i == A.size()) A.clear();
    else A.erase(A.begin(),A.begin()+i);
    return A;
}
