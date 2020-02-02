#include<iostream>
using namespace std;
bool isprime(int a)
{
	if(a==1)
	{
		return false;
	}
	
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		return false;
	}
	return true;
}
int main()
{
	int a;
	cin>>a;
	cout<<isprime(a);
	return 0;	
}
