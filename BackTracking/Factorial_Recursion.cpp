 #include <iostream>
using namespace std;

int fact(int val)
{
	if(val<=1) return 1;
	return val*fact(val-1);
}

int main(int argc, char const *argv[])
{
	cout<<fact(6)<<endl;
	return 0;
}