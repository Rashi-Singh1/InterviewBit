
string solve(string A, int B)
{
	//cout<<A<<endl;
	if(A.size() <=1 || B <=1) return A;
	else
	{
		string ans;
		for(int j = 1;j<=B;j++)
		{
			int i = j-1;
			//cout<<"print basic "<<i<<endl;
			if(i < A.size()) ans+=A[i];
			bool used = false;
			bool cas = false;
			while(i<A.size()){
				if(used == true)
				{
					//cout<<"1     "<<j<<" "<<i<<endl;
					if(j-1 != 0) {
						//cout<<"2     "<<j<<" "<<i<<endl;
						i+=((j-1)*2);
					}
					used = false;
				}
				else if(used == false)
				{
					//cout<<"3     "<<j<<" "<<i<<endl;
					if((j)%B!=0) {
						//cout<<"4     "<<j<<" "<<i<<endl;
						i+=((B-j)*2 );
					}
					used = true;
				}
				if(((j)%B == 0 && used == true)|| (j-1 == 0 && used == false)){

				}else{
					//cout<<"print "<<j<<" "<<i<<endl;
					if(i<A.size()) ans+=A[i];
				}
				// if(i+1+((B-i-1)*2) < A.size() && ((i)%A.size()!=0)) {
				// 	//cout<<i+1+(B-i-1)*2<<endl;
				// 	ans+=A[i+1+(B-i-1)*2];
				// }
				// i++;
			}
		}
		return ans;
	}
}

//after reset
string Solution::convert(string A, int rows) {
    if(rows == 1 || A.size()<=1) return A;
    int i = 0;
    string ans;
    bool slopeNeg = true;
    for(int j = 0;j<rows;j++)
    {
        i = j;
        slopeNeg = true;
        while(i<A.size())
        {
            ans+=A[i];
            if((slopeNeg && j!=rows-1) || j==0)
            {
                i+=(rows-j-1)*2;
                slopeNeg = false;
            }
            else
            {
                i+=j*2;
                slopeNeg = true;
            }
        }
    }
    return ans;
}

string BestSolution( string A, int B)
{
	if(B <= 1) return A;
	else{
		int rows = B-1;
		int i = 0;
		string ans;
		while( j<B )
		{
			i = j;
			while(i < A.size())
			{
				ans+=A[i];
				i+=(rows - i%rows)*2;
			}
			j++;
		}
		return ans;
	}
}


int main()
{
	string A = "RASHISINGH";
	cout<<solve(A,3)<<endl;
}