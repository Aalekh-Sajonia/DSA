#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int arr[501];
int dp[501][101];
int main()
{
	int n,m=INT_MIN;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		m = max(arr[i],m);
		dp[i][arr[i]]=1;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				for(int k=1;k<=m;k++)
				{
					int gd = __gcd(k,arr[i]);
					dp[i][gd] += dp[j][k];
					if(dp[i][gd]>=mod)
					dp[i][gd]%=mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans += dp[i][1];
		if(ans>=mod)
		{
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
	
}
