#include <iostream>
#include <cstdlib>
#include<vector> 
using namespace std;

//

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int startX = X[0];
    int startY = Y[0];
    int count = 0;
    for(int i = 1 ; i < X.size() ; i++)
    {
        //translocated the next stop s.t. (startX,startY) can be treated as (0,0)
        //took the abs, bcs from origin does not matter in which quadrant
        int tempX = abs(X[i] - startX);
        int tempY = abs(Y[i] - startY);

        //from (0,0), the number to steps to go to (a,b) is max(a,b), consider ex of (8,5) from (0,0), go to 5,5 then 8,5
        count+= max(tempX,tempY);
        startX = X[i];
        startY = Y[i];
    }
    return count;
}


//

int coverPoints(vector<int> &A, vector<int> &B) {
    int startX = A[0];
    int startY = B[0];
    int total = 0;
    for(int i = 1;i<A.size();i++)
    {
        int option1X = A[i];
        int option1Y = startX + startY - option1X;
        int option2Y = B[i];
        int option2X = startX+startY - option2Y;
        int option3X = A[i];
        int option3Y = option3X-(startX - startY) ;
        int option4Y = B[i];
        int option4X = startX - startY + option4Y;
        int path1 = abs(option1X - startX) + abs(option1Y - B[i]);
        int path2 = abs(option2X - startX) + abs(option2X - A[i]);
        int path3 = abs(option3X - startX) + abs(option3Y - B[i]);
        int path4 = abs(option4X - startX) + abs(option4X - A[i]);
        int min1 = min(path1,path2);
        int min2 = min(path3,path4);
        total+=min(min1,min2);
        startX = A[i];
        startY = B[i];
    }
    return total;
}

int main(int argc, char const *argv[])
{
	vector<int> A = { 4, 8, -7, -5, -13, 9, -7, 8 };
	vector<int> B = { 4, -15, -10, -3, -13, 12, 8, -8 };
	int total = coverPoints(A,B);
	cout<<"result "<<total<<endl;
	return 0;
}