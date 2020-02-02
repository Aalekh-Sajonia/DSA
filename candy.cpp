#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int dp[1<<n];
	for(int i=0;i<(1<<n);i++)
	{
		dp[i]=0;
	}
	dp[0] = 1;
	for(int mask=0;mask<((1<<n)-1);mask++)
	{
		int temp = mask;
		int k=0;
		while(temp>0)
		{
			if((temp%2)==1)
			k++;
			temp = temp/2;
		}
		
		for(int j=0;j<n;j++)
		{
			if(!(mask&(1<<j)))
			{
				if(arr[k][j])
				{
					dp[mask|(1<<j)] += dp[mask];
				}
			}
		}
	}
	
	
	cout<<dp[(1<<n)-1]<<endl;
	
	return 0;
}
