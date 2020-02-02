#include<bits/stdc++.h>
using namespace std;
int dp[120][120];
int min_cost(int **arr,int city,int bus,int n,int m)
{
	if(city>=n||bus>=m)
	{
		return 0;
	}
	
	if(dp[city][bus]!=-1)
	return dp[city][bus];
	int ans;
	if(bus==0)
	{
	ans = min(arr[city][bus] + min_cost(arr,city+1,bus,n,m) , arr[city][bus] + min_cost(arr,city+1,bus+1,n,m));
	}
	else if(bus==m-1)
	{
		ans = min(arr[city][bus] + min_cost(arr,city+1,bus,n,m), arr[city][bus] + min_cost(arr,city+1,bus-1,n,m));
	}
	else
	{
	ans = min(arr[city][bus]+min_cost(arr,city+1,bus,n,m), 
			min(arr[city][bus] + min_cost(arr,city+1,bus-1,n,m),arr[city][bus] + min_cost(arr,city+1,bus+1,n,m)));
	}
	
	dp[city][bus] = ans;
	return ans;
		
}

int main()
{
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[m];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	memset(dp,-1,sizeof(dp));
	int mini = INT_MAX;
	int flag=0;
	while(1)
	{
		mini  = min(min_cost(arr,0,flag,n,m),mini);
		flag++;
		if(flag==m)
		break;
	}
	cout<<mini<<endl;
	return 0;
}
