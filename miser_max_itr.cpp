#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,mi,i,j;
	int dp[101][101] = {0};
	cin>>n>>m;
	for(i=0;i<=n;i++)
		dp[i][m+1] = dp[i][0] = 100000;

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>dp[i][j];
			
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			dp[i][j] += min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
			
	mi = 100000;
	
	for(i=1;i<=m;i++)
		if(dp[n][i]<mi)
			mi = dp[n][i];
			
	cout<<mi<<endl;
	return 0;
}
