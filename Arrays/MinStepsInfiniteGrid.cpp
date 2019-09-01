int solve(vector<int>&A, vector<int> &B)
{
	if(A.size() == 0) return 0;
	else{
		int ans = 0;
		for(int i  = 0;i<A.size()-1;i++)
		{
			ans+=max(abs(A[i+1]-A[i]),abs(B[i+1]-B[i]));
		}
		return ans;
	}
}

/*
	While X and Y are positive, you will move along the diagonal and X and Y would both reduce by 1. 
	When one of them becomes 0, you would move so that in each step the remaining number reduces by 1.

	In other words, the total number of steps would correspond to max(X, Y).
*/