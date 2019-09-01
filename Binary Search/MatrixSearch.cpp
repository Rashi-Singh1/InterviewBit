#include <iostream>
#include <vector>
using namespace std;

/*O( log(row) + log(col) )*/
int sol(vector<vector<int> > &array, int x)
{
	int start = 0;
	int end = array.size()-1;
	int mid;
	int r;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(array[mid][0] == x) return 1;
		else if(array[mid][0] > x) end = mid-1; 
		else {
			r = mid;
			start = mid+1;
		}		
	}
	start = 0;
	end = array[r].size()-1;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(array[r][mid] == x) return 1;
		else if(array[r][mid] < x) start = mid+1;
		else end = mid-1;
	}
	return 0;
}

int main()
{
	vector<vector<int> > array = {{1,2,3,4},{5,6,7,8},{8,9,10,11}};
	cout<<sol(array,9)<<endl;
}

//		O( row*log(col) )   or O(col*log(row)) also exists, usme search for row and check for the whole column