#include<bits/stdc++.h>
using namespace std;
int number(int a)
{
	if(a==1||a==0)
	{
		return 1;
	}
	
	int x,y;

	x = number(a-1);
	y = number(a-2);
	int m = pow(10,9)+7;
	long x1 = (long)x*x;
	long y1 = (long)x*y*2;
	
	int ans1 = (int)(x1 % m);
	int ans2 = (int)(y1 % m);
	int ans = (ans1+ans2)%m;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<number(n);
	return 0;
}
