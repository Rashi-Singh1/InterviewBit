//For placement - 
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int > > ans(A,vector<int> (A,0));
    int x = 0, y = 0, xleft = 0, yleft = 0;
    int k = 1;
    while(k <= A*A){
        while(k <= A*A && x < A - xleft){
            ans[y][x++] = k++;
        }
        x--; y++;
        while(k <= A*A && y < A - yleft){
            ans[y++][x] = k++;
        }
        y--; x--;
        yleft++;
        while(k <= A*A && x >= xleft){
            ans[y][x--] = k++;
        }
        x++; y--;
        xleft++;
        while(k <= A*A && y >= yleft){
            ans[y--][x] = k++;
        }
        y++; x++;
    }
    return ans;
}

vector<vector<int> > Solution::generateMatrix(int A) {
    if(A == 0) return NULL;
    int x = 0;
    int y = 0;
    int k = 0;
    
    vector<int> temp(A,0);
    vector<vector<int>> sol(A,temp);
    
    int row = A;
    int col = A;
    
    int xLimit = col;
    int yLimit = row;
    while(k < row*col)
    {
        while(x < xLimit && k < row*col) {
            sol[y][x++] = k+1;
            k++;
        }
        x--;
        y++;
        while(y < yLimit && k < row*col)
        {
            sol[y++][x] = k+1;
            k++;
        }
        y--;
        x--;
        yLimit--;
        while(x >= col-xLimit && k < row*col)
        {
            sol[y][x--] = k+1;
            k++;
        }
        x++;
        y--;
        xLimit--;
        while(y >= row-yLimit && k < row*col)
        {
            sol[y--][x] = k+1;
            k++;
        }
        x++;
        y++;
    }
    return sol;
}

//

vector<vector<int> > generateMatrix(int key) {
    vector<vector<int> > A;
    for(int i = 0 ;i<key;i++)
    {
        vector<int> temp;
        for(int j = 0;j<key;j++)
        {
            temp.push_back(0);
        }
        A.push_back(temp);
    }
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
            if(k<total) A[i][j++] = k;
            //answer.push_back(A[i][j++]);
            k++;
            if(k>=total) break;
        }
        j--;
        i++;
        while(i < (row-iterationY) && i>=0)
        {
            if(k<total) A[i++][j] = k;
            k++;
            if(k>=total) break;
        }
        j--;
        i--;
        while(j>=iterationX && j<col)
        {
            if(k<total) A[i][j--] = k;
            k++;
            if(k>=total) break;
        }
        iterationX++;
        j++;
        i--;
        while(i>=(iterationY+1) && i<row)
        {

            if(k<total) A[i--][j] = k;
            k++;
            if(k>=total) break;
        }
        iterationY++;
        i++;
        j++;
    }   
    return A;
}

int main(int argc, char const *argv[])
{
	int a = 8;
    vector<vector<int> > A;
	A = generateMatrix(a);
	for (int i = 0; i < a; ++i)
	{
		/* code */
		for (int j = 0; j < a; ++j)
		{
			/* code */
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}