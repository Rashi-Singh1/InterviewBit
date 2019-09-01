#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void print(vector<vector<int> >& A)
{
	for(int i = 0;i<A.size();i++)
	{
		for(int j = 0;j<A[i].size();j++)
			printf("%2d ",A[i][j]);
		cout<<endl;
	}cout<<endl;
}

bool valid(vector<vector<int> >&A,int move,int x,int y)
{
	cout<<"move : "<<move<<" "<<x<<" "<<y<<endl;
	print(A);
	if(move == 64) return true;
	bool flag = false;
	for(int i = x-2;i<=x+2;i++)
	{
		for(int j = y-2;j<=y+2;j++)
		{
			if(i>=0 && i<8 && j>=0 && j<8 && i!=x && j!=y && i+j!=x+y && i-j!=x-y && A[i][j] == -1)
			{
				A[i][j] = A[x][y]+1;
				if(valid(A,move+1,i,j)) return true;
				else A[i][j] = -1;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	vector< vector<int> > A;
	for (int i = 0; i < 8; ++i)
	{
		vector<int> temp(8);
		A.push_back(temp);
	}
	for (int i = 0; i < A.size(); ++i)
	{
		for(int j = 0;j<A[0].size();j++)
		{
			A[i][j] = -1;
		}
	}
	int x = 1;
	int y = 4;
	A[x][y] = 0;
	auto temp = valid(A,1,x,y);
	print(A);
	return 0;
}