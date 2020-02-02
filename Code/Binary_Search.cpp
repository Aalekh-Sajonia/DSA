#include<iostream>
using namespace std;
int binser(int *a,int n,int ser)
{
	int f=0,m,l=n-1;
	m=n/2;
	int get=1;
	while(get)
	{
		if(a[m]==ser)
		return m;
		else if(a[m]<ser)
			f=m+1;
		else 
			l=m-1;
		m=(f+l)/2;
	}
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int ans = binser(a,10,9);
	cout<<ans;
}
