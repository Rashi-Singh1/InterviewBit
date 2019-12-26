#include <iostream>
#include <vector>
using namespace std;
//For placements - 

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int x = 0;
    int y = 0;
    int k = 0;
    
    vector<int> ans;
    
    int row = A.size();
    if(row == 0) return ans;
    
    int col = A[0].size();
    if(col == 0) return ans;
    
    int xLimit = col;
    int yLimit = row;
    while(k < row*col)
    {
        while(x < xLimit && k < row*col) {
            ans.push_back(A[y][x++]);
            k++;
        }
        x--;
        y++;
        while(y < yLimit && k < row*col)
        {
            ans.push_back(A[y++][x]);
            k++;
        }
        y--;
        x--;
        yLimit--;
        while(x >= col-xLimit && k < row*col)
        {
            ans.push_back(A[y][x--]);
            k++;
        }
        x++;
        y--;
        xLimit--;
        while(y >= row-yLimit && k < row*col)
        {
            ans.push_back(A[y--][x]);
            k++;
        }
        x++;
        y++;
    }
    return ans;
}


//
vector<int> spiralOrder(const vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int i = 0,j = 0;
    int k = 0;
    int total = row*col;
    int iterationX = 0;
    int iterationY = 0;
    vector <int> answer;
    while(k < total)
    {
        while(j < (col-iterationX) && j>=0 )
        {
            answer.push_back(A[i][j++]);
            k++;
            if(k>=total) break;
        }
        j--;
        i++;
        while(i < (row-iterationY) && i>=0)
        {

            answer.push_back(A[i++][j]);
            k++;
            if(k>=total) break;
        }
        j--;
        i--;
        while(j>=iterationX && j<col)
        {

            answer.push_back(A[i][j--]);
            k++;
            if(k>=total) break;
        }
        iterationX++;
        j++;
        i--;
        while(i>=(iterationY+1) && i<row)
        {

            answer.push_back(A[i--][j]);
            k++;
            if(k>=total) break;
        }
        iterationY++;
        i++;
        j++;
        
    }
    return answer;
}

int main()
{
	vector<vector<int> > A = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

	vector<int> answer = spiralOrder(A);
	for (int i = 0; i < answer.size(); ++i)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}


//After reset
vector<int> Solution::spiralOrder(const vector<vector<int> > &a) {
    int row = a.size();
    int col = a[0].size();
    int total = row*col;
    int i = 0;
    int j = 0;
    int k = 0;
    int x = 0,y = 0;
    vector<int> sol;
    while(k<total)
    {
        while(j < col && k < total)
        {
            sol.push_back(a[i][j]);
            j++;
            k++;
        }
        col--;
        j--;
        i++;
        while(i<row && k < total)
        {
            sol.push_back(a[i][j]);
            i++;
            k++;
        }
        row--;
        i--;
        j--;
        while(j >= y  && k < total)
        {
            sol.push_back(a[i][j]);
            j--;
            k++;
        }
        j++;
        y++;
        i--;
        while(i > x & k < total)
        {
            sol.push_back(a[i][j]);
            i--;
            k++;
        }
        i++;
        j++;
        x++;
    }
    return sol;
}
