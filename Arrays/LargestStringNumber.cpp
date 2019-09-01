/*My sol using mergesort which worked for all but one*/

int compare(string* A, int index1, int index2)
{
    for(int j = 0;j<min(A[index1].size(),A[index2].size());j++)
    {
        if(A[index1][j] > A[index2][j])
        {
            return index1;
        }
        else if( A[index1][j] < A[index2][j])
        {
            return index2;
        }
    }
    if(A[index1].size() > A[index2].size())
    {
        if(A[index1][A[index2].size()] > A[index2][0]) return index1;
        else return index2;
    }else{
         if(A[index2][A[index1].size()] > A[index1][0]) return index2;
        else return index1;
    }
}

void merge(string* value, int start,int mid, int end)
{
    string array[end-start+1];
    int k = 0,i=start,j=mid+1;
    while(i<=mid && j<=end)
    {
        int copy = compare(value,i,j);
        if (copy == i)
        {
            array[k++] = value[i ];
            i++;
        }
        else
        {
            array[k++] = value[j];
            j++;
        }
    }
    while(i <= mid){
        array[k++] = value[i];
        i++;
    }
    while(j <= end){
        array[k++] = value[j];
        j++;
    }
    for (int i = 0; i < end-start+1; ++i)
    {
        value[i+start] = array[i];
    }
}


void mergeSort(string* array,int start, int end)
{
    if (start < end)
    {
        int mid = (start+end)/2;
        mergeSort(array,start,mid);
        mergeSort(array,mid+1,end);
        merge(array,start,mid ,end);
    }
}


string Solution::largestNumber(const vector<int> &B) {
    string temp[A.size()];
    for(int i = 0;i<A.size();i++)
    {
        temp[i] = to_string(A[i]);
    }
  string ans;
  mergeSort(temp,0,A.size()-1);
  for(int i = 0;i<A.size();i++)
  {
      ans += temp[i];

  }
  long long int numb;
  stringstream geek2(ans);
  geek2 >> numb;
  if(numb == 0)
        ans = to_string(numb);

  return ans;
}



/*Actual solution*/
//very goood soution
string Solution::largestNumber(const vector<int> &B) {

    vector<int> A(B);
    sort(A.begin(), A.end(),
        [](int a, int b)
        {
            int sizeOfA = log10(a) + 1;
            int sizeOfB = log10(b) + 1;
            if(sizeOfA == sizeOfB) return a > b;
            
            long long int concat1;
            long long int concat2;
            concat1 = pow(10.0, sizeOfB)*a + b;
            concat2 = pow(10.0, sizeOfA)*b + a;
            
            return concat1 > concat2;
        }
    );

    string res;

    for(auto n : A){
        if(n != 0)
        res.append(to_string(n));
    }

    if(res.size() == 0) res.append("0");

    return res;
}


///editorial also good
static bool compareNum(string a, string b) {
    return a + b > b + a;
}

string largestNumber(const vector<int> &num) {
    string result;
    vector<string> str;
    for (int i = 0; i < num.size(); i++) {
        str.push_back(to_string(num[i]));
    }
    sort(str.begin(), str.end(), compareNum);
    for (int i = 0; i < str.size(); i++) {
        result += str[i];
    }

    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
    return result.substr(pos);
}

//after Reset, worked
void merge(vector<string> &A, int start, int mid, int end)
{
    vector<string> buffer;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end)
    {
        string one = A[i] + A[j];
        string two = A[j] + A[i];
        if(stoll(one) > stoll(two))
        {
            buffer.push_back(A[i++]);
        }else{
            buffer.push_back(A[j++]);
        }
       
    }
    while(i<=mid)
    {
        buffer.push_back(A[i++]);
    }
    while(j<=end)
    {
        buffer.push_back(A[j++]);
    }
    for(int i = 0;i<buffer.size();i++)
    {
        A[i+start] = buffer[i];
    }
}

void mergeSort(vector<string> &A, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        mergeSort(A,start, mid);
        mergeSort(A,mid+1,end);
        merge(A,start,mid, end);
    }
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> ha;
    for(int i = 0;i<A.size();i++)
    {
        ha.push_back(to_string(A[i]));
    }
    mergeSort(ha,0,ha.size()-1);
    string ans;
    for(int i = 0;i<A.size();i++)
    {
        ans+=ha[i];
    }
    int i = 0;
    int trash = ans.size();
    while(i<ans.size())
    {
        if(ans[i] == '0') i++;
        else break;
    }
    if(i < ans.size() ) ans = ans.substr(i);
    else if(trash!=0) return "0";
    else return "";
    return ans;
}

//again Khud
bool compare(string A, string B){
    string AB = A+B;
    string BA = B+A;
    return stoll(AB) > stoll(BA);
}
string Solution::largestNumber(const vector<int> &A) {
    if(A.size() == 0) return "";
    vector<string> B;
    for(int i = 0;i<A.size();i++)
    {
        B.push_back(to_string(A[i]));
    }
    sort(B.begin(),B.end(),compare);
    string ans;
    for(int i = 0;i<B.size();i++)
    {
        ans+=B[i];
    }
    int k = 0 ;
    while(k<ans.size())
    {
        if(ans[k] == '0') k++;
        else break;
    }
    if(k < ans.size()) ans = ans.substr(k);
    else return "0";
    return ans;
}
