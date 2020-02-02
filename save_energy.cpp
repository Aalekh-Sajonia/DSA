#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long *arr = new long[n];
	for(long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long i=0;
	long ans = 0;
	while(i<(n-1))
	{
		long j = i+1;
		while(j<(n-1))
		{
			if((abs(arr[i])>abs(arr[j])) ||
				((abs(arr[i])==abs(arr[j]))&&arr[i]>0))
				{
					break;	
				}
			else
			{
				j++;
			}
		}
		ans += (j-i)*arr[i] + (j*j-i*i)*arr[i]*arr[i];
		i = j;
	}
	cout<<ans;
	return 0;
}
