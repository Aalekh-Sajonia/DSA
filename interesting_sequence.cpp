#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,l;
	cin>>n>>k>>l;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int min = INT_MAX;
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(arr[i]<min)
		{
			min = arr[i];
		}
	}

	int ans = 1e9;
	while(min<=max)
	{
		int incr = 0;
		int decr = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]<min)
			{
				incr += (min-arr[i]);
			}
			if(arr[i]>min)
			{
				decr += (arr[i]-min);
			}
		}
		if(incr>=decr)
		{
			int a1 = incr-decr;
			int tempans;
			tempans = (decr*k) + (a1*l);
			cout<<min<<" "<<tempans<<endl;
			if(ans>tempans)
			{
				ans = tempans;
			}
		}
		min++;
	}
	
	if(ans == 1e9)
	{
		cout<<"0";
	}
	else
	cout<<ans;
	return 0;
}
