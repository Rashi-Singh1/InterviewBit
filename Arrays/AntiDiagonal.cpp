//For placement - 
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    if(A.size() == 0) return A;
    vector<vector<int> > ans(2*(A.size()) - 1);
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0; j < A[0].size() ; j++){
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;
}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > ans( (2*A.size())-1);
    for(int i = 0;i<A.size();i++)
    {
        for(int j = 0;j < A[i].size();j++)
        {
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;
}

//


/*editorial : very good and easy solution*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;//number of vectors in ans
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(A[i][j]);//sum of index values in 2d array gives the index in ans
    }
    return ans;
}

//after Reset
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    if(A.size() == 0) return A;
    vector<vector<int> > ans;
    int n = A.size();
    for(int sum = 0;sum<n;sum++){
        vector<int> temp;
        int row = 0;
        int col = sum;
        for(int i = 0;i<=sum;i++)
        {
            temp.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(temp);
    }
     for(int sum = n-2; sum>=0 ;sum--){
        vector<int> temp;
        int row = n-sum-1;
        int col = n-1;
        for(int i = 0;i<=sum;i++)
        {
            temp.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(temp);
    }
    return ans;
}



/*My solution*/

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int row = A.size();
    vector<vector<int> > ans;
    for(int i = 0;i<row;i++)
    {
        vector<int> temp;
        int k = 0;
        int r = 0; int c = i;
        while(k<i+1)
        {
            if(r<row && c<row && r>=0 && c>=0) {
            	temp.push_back(A[r][c]);
            	k++;
            }
            r++;
            c--;
        }

        ans.push_back(temp);
    }
    for(int i = 1;i<row;i++)
    {
    	vector<int> temp;
        int k = 0;
        int r = i; int c = row-1;
        while(k<row-i)
        {
            if(r<row && c<row && r>=0 && c>=0) {
            	temp.push_back(A[r][c]);
            	k++;
            }
            r++;
            c--;
        }

        ans.push_back(temp);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > A = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int> > ans;
    ans = diagonal(A);
    for(int i = 0;i<ans.size();i++)
    {
    	for (int j = 0; j < ans[i].size(); ++j)
    	{
    		/* code */
    		cout<<ans[i][j]<<" ";
    	}
    	cout<<endl;
    }

	return 0;
}