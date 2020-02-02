#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[m];
	}
	
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++)
	{
		dp[i] = new int[m+1];
	}
	
	for(int i=0;i<m+1;i++)
	{
		dp[0][i] = 1 ;		
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			if(i>=1)
			{
				if(arr[i][j]>=arr[i-1][j])
				{
					dp[i][j] = dp[i-1][j];
				}
				else
				{
					dp[i][j] = i+1;
				}
			}
		}
	}
	
	int qr;
	cin>>qr;
	while(qr--)
	{
		int a,b;
		cin>>a>>b;
		int flag = 0;
		for(int i=0;i<m;i++)
		{
			if(dp[b-1][i]<=a)
			{
				cout<<"YES"<<endl;
				flag = 1;
				break;
			}
		}
		if(flag==0)
		cout<<"NO"<<endl;
	}
/*	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
    return 0;
}

