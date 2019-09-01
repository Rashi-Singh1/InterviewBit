int sol(int A, int B)
{
	while(__gcd(A,B)!=1)	//two underscore
	{
		A/=__gcd(A,B);
	}
	return A;
}