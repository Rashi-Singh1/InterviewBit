/*Editorial : very good solution*/
vector<int> Solution::getRow(int A) {
    vector<int> ans = {1};
    int temp = 1;
    for(int i = 1; i <= A ; i++){
        temp*=(A-i+1);
        temp/=i;
        ans.push_back(temp);
    }
    return ans;
}

vector<int> Solution::getRow(int A) {
    vector<int> ans;
    for(int i = 0;i<=A;i++)
    {
        ans.push_back(1);
    }
    for(int i=1;i<=A;i++)
        ans[i] = ans[i-1]*(A-i+1)/i;			//think of it as to convert from nCr to nC(r+1)
    											//7C0 to 7C1 ke liye   7!    to    7!
    											//					  7! 0!       6! 1!
    return ans;									// everytime neeche se ek factor kam karna h here 7! to 6! ke liye 7
}												// and ek factor badhana h from 0 to 1 by mutiplying by 1


//after Reset
//same for placement - 
vector<int> Solution::getRow(int A) {
    vector<int> ans;
    ans.push_back(1);
    for(int i = 1;i<=A;i++)
    {
        ans.push_back((ans.back()*(A-i+1))/i);
    }
    return ans;
}
/*
    time complexity : O(A)
    space complexity : O(A)
*/


/*My solution :  did not work for larger cases, idk why*/

int numb = 7;
int factorial(int* array, int key)
{
    if(array[key] != -1) return array[key];
    if(key == 0 | key == 1) return 1;
    array[key] = key*factorial(array,key-1);
    
    return array[key];
}

vector<int> getRow(int A) {
    vector<int> answer;
    int array[A+1];
    for(int i = 0;i<=A;i++)
    {
        array[i] = -1;
    }
    array[0] = array[1] = 1;
    for(int i = 0;i<=A;i++)
    {
        int value = factorial(array,A)/(factorial(array,i)*factorial(array,A-i));
        answer.push_back(value);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
	int a = numb;
	vector<int> ans;
	ans = getRow(a);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}