#include<bits/stdc++.h>
using namespace std;

int expo(int a,int n)
{
	if(n==1)
	{
		return a;
	}
	if(n == 0)
	{
		return 1;
	}
	int r = expo(a,n/2);
	if(n%2==0)
	{
		return r*r;
	}
	else
	{
		return r*a*r;
	}
}

int rExpo(int a,int n,int m)
{
	if(n==1)
	{
		return a;
	}
	if(n==0)
	{
		return 1;
	}
	int r = rExpo(a,n/2,m);
	if(n%2==0)
	{
		return (r%m * r%m)%m;
	}
	else
	{
		return (r%m * r%m * a)%m;
	}
}

int main()
{
	int a,n,m;
	cin>>a>>n>>m;
	cout<<expo(a,n)%m;
	cout<<endl;
	cout<<rExpo(a,n,m);
	return 0;
}
