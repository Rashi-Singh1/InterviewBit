/*My sol*/
int ceilSearch(vector<int> arr, int low, int high, int x) 
{ 
  int mid;     
  
  /* If x is smaller than or equal to the first element, 
    then return the first element */
  if(x <= arr[low]) 
    return low;  
  
  /* If x is greater than the last element, then return -1 */
  if(x > arr[high]) 
    return -1;   
  
  /* get the index of middle element of arr[low..high]*/
  mid = (low + high)/2;  /* low + (high - low)/2 */
  
  /* If x is same as middle element, then return mid */
  if(arr[mid] == x) 
    return mid; 
      
  /* If x is greater than arr[mid], then either arr[mid + 1] 
    is ceiling of x or ceiling lies in arr[mid+1...high] */  
  else if(arr[mid] < x) 
  { 
    if(mid + 1 <= high && x <= arr[mid+1]) 
      return mid + 1; 
    else 
      return ceilSearch(arr, mid+1, high, x); 
  } 
  
  /* If x is smaller than arr[mid], then either arr[mid]  
     is ceiling of x or ceiling lies in arr[mid-1...high] */    
  else
  { 
    if(mid - 1 >= low && x > arr[mid-1]) 
      return mid; 
    else     
      return ceilSearch(arr, low, mid - 1, x); 
  } 
} 

/*My practice for floorSearch*/
int floorSearch(vector<int> &A, int start, int end, int x)
{
    while(start <= end)
    {
        if(x < A[start]) return -1;
        if(x >= A[end]) return end;
        int mid = (start+end)/2;
        if(A[mid] == x) return mid;
        else if( A[mid] < x)
        {
            if(mid < end && A[mid+1] >x)
                return mid;
            else
                start = mid + 1;
        }
        else
        {
            if(mid > start && A[mid-1] <= x)
                return mid-1;
            else
                end = mid-1;
        }
    }
    return -1;
}


int binarySearch(vector<int> arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 


int Solution::solve(vector<int> &A, int len, int val) {
    if(len == 0 || A.size() == 0 || val == 0) return 0;
    if(  len < (int )( (int)log10(val) +1 )   )
    {
        if(binarySearch(A,0,A.size()-1,0) == -1 || len == 1)    //better use A.front()
        {
            return pow(A.size(),len);
        }else{
            return (A.size()-1)*pow(A.size(),len-1);
        }
        
    }else if(len > (int)( (int)log10(val) +1 ) ){
        return 0;
    }else{
        int  n = len;
        long long int count = 0;
        int zeroPresent = 0;
        if(binarySearch(A,0,A.size()-1,0) != -1){
            zeroPresent = 1;
        }
        string name = to_string(val);
        for(int i = 0;i<len;i++)
        {
            int index = ceilSearch(A,0,A.size()-1,(int)(name[i]-'0'));
            if(index == 0 && (int)(name[i]-'0') < A[0])
            {
                return count;
            }
            if(index == -1)
            {
                if(zeroPresent == 0 || len == 1 || i!=0)
                {
                    count+= pow(A.size(),n);
                }else{
                    count+= (A.size()-1)*pow(A.size(),n-1);
                }
                return count;
            }else{
                if(zeroPresent == 0 || i!=0 || len == 1)
                {
                    count+= index*pow(A.size(),n-1);
                }else{
                    count+= (index-1)*pow(A.size(),n-1);
                }
                
            }
            if((int)(name[i]-'0') < A[index])
            {
                return count;
            }
            n--;
        }
        return count;
    }
}

/*Other Sol*/


int solve_b(vector<int> &A, int B, int C, bool first_digit=false) {
    
    if (C <= 0 || B <= 0 || A.size() == 0)
        return 0;
    
    string rep = to_string(C);
    int max_number = rep.at(0) - '0';
    
    if(B < rep.size()){
        if(A.front() == 0 && B > 1)
            return (A.size() - 1) * pow( A.size(), B-1 );
        else
            return pow( A.size() , B);
    }
    else if (B > rep.size())
        return 0;
    else{
        int count = 0;
        
        for(auto a : A){
            
            if(a == 0 && first_digit && rep.size() > 1) continue;
            
            if(a < max_number){
                count += pow( A.size(), rep.size() - 1);
            }else if(a == max_number){
                if(rep.size() == 1) continue;
                
                int new_c = stoi(rep.substr(1));
                
                if(A.front() != 0){
                    count += solve_b(A, B-1, new_c, false);
                }else{
                    count += solve_b(A, to_string(new_c).size(), new_c, false);
                }
                
            }
        }
        
        return count;
    }
}

int Solution::solve(vector<int> &A, int B, int C) {
    return solve_b(A, B, C, true);
}