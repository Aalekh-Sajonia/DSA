#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int n,k,x;
	cin>>n>>k>>x;
	int arr1[1024];
	int arr2[1024];
	memset(arr1, 0, sizeof(arr1)); 
	memset(arr2, 0, sizeof(arr1)); 
 	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		arr1[a]++;
		arr2[a]++;
	}
	for(int i=0;i<k;i++)
	{
		int c=0;
		for(int j=0;j<=1023;j++)
		{
			if(arr1[j]==0)
			continue;
			if(c%2==0)
			{
				int p = (arr1[j]+1)/2;
				arr2[j^x] += p;
				arr2[j] -= p;
			}
			else
			{
				int p = arr1[j]/2;
				arr2[(j^x)] += p;
				arr2[j] -= p;
			}
			c += arr1[j];
		}
		
		for(int t=0;t<=1023;t++)
		{
			arr1[t] = arr2[t];
		}
	}
	
	for(int i=1023 ; i>=0; i--)
	{
		if(arr1[i]>0)
		{
			cout<<i<<" ";
			break;
		}
	}
	
	for(int i=0;i<=1023;i++)
	{
		if(arr1[i]>0)
		{
			cout<<i;
			break;
		}
	}
	
	
    return 0;
}

