#include <bits/stdc++.h>
using namespace std;

int min_Salary(int *cap,int *ass,int n,int x,int **dp)
{
	if(n==0)
	return 0;
	
	if(dp[n][x]!=-1)
	{
		return dp[n][x];
	}
	
	if(x==0)
	{
		return dp[n][x] = ass[0] + min_Salary(cap+1,ass+1,n-1,x+1,dp);
	}
	if(x==n)
	{
		return dp[n][x] = cap[0] + min_Salary(cap+1,ass+1,n-1,x-1,dp) ;
	}
	else
	{
		return dp[n][x] = min(ass[0]+min_Salary(cap+1,ass+1,n-1,x+1,dp),
					cap[0] + min_Salary(cap+1,ass+1,n-1,x-1,dp));
	}
	
}



int main()
{
	int n;
	cin>>n;
	int cap[n];
	int ass[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>cap[i]>>ass[i];
	}
	int **dp = new int*[n+10];
	
	for(int i=0;i<n+10;i++)
	{
		dp[i] = new int[n/2+10];
	}
	
	
	for(int i=0;i<n+10;i++)
	{
		for(int j=0;j<n/2+10;j++)
		dp[i][j] = -1;
	}
	
	
	cout<<min_Salary(cap,ass,n,0,dp);
	
    return 0;
}

